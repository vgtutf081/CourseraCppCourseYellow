#pragma once

#include <set>
#include "date.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <utility>
#include <set>

class Database {
public:
    void Add(const Date& date, const string& event);

    ostream& Print(ostream& os) const;

    template<typename Pred>
    int RemoveIf(Pred pred) {
        int removedCount = 0;
        vector<Date> dfd;

        for (auto& record : storage) {
            auto& date = record.first;
            auto& events = record.second.orderLog;

            auto it = stable_partition(events.begin(), events.end(),
                [date, pred](string event) {
                return !pred(date, event);
            });

            int delCount = events.end() - it;
            for (int i = 0; i < delCount; ++i) {
                record.second.addingLog.erase(events.back());
                events.pop_back();
            }
            removedCount += delCount;

            if (events.size() == 0) {
                dfd.push_back(date);
            }
        }

        for (const auto& date : dfd) {
            storage.erase(date);
        }

        return removedCount;
    }

    template<typename Pred>
    vector<string> FindIf(Pred p) const {
        vector<string> result;
        for (auto& record : storage) {
            auto& date = record.first;
            auto& events = record.second.orderLog;
            for (auto& event : events) {
                if (p(date, event)) {
                    ostringstream os;
                    os << date << " " << event;

                    result.push_back(os.str());
                }
            }
        }
        return result;
    }

    string Last(const Date& d) const;

private:
    struct EventLogs {
        set<string> addingLog;
        vector<string> orderLog;
    };

    map<Date, EventLogs> storage;
};
