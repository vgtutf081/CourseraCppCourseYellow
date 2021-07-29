//============================================================================
// Name        : taskTracker.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


class TeamTasks {
public:
    // ѕолучить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const
    {
        return PersonTasks.at(person);
    }

    // ƒобавить новую задачу (в статусе NEW) дл€ конкретного разработчитка
    void AddNewTask(const string& person)
    {
        auto& tasks_info = PersonTasks[person];
        ++tasks_info[TaskStatus::NEW];
    }

    // ќбновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count)
    {

        TasksInfo upgrade;
        TasksInfo update;
        TasksInfo untouch;

        auto & temp_tasks_info = PersonTasks[person];
        for (auto& item : temp_tasks_info)
        {
            if (item.first == TaskStatus::NEW)
            {
                if (item.second > 0)
                {
                    int new_status_count = item.second;
                    while (new_status_count > 0 && task_count > 0)
                    {
                        ++update[TaskStatus::IN_PROGRESS];
                        ++upgrade[TaskStatus::IN_PROGRESS];
                        --new_status_count;
                        --task_count;
                    }
                    if (new_status_count > 0)
                    {
                    	untouch[TaskStatus::NEW] += new_status_count;
                        upgrade[TaskStatus::NEW] += new_status_count;
                    }
                }
            }
            if (item.first == TaskStatus::IN_PROGRESS)
            {
                if (item.second > 0)
                {
                    int in_progress_status_count = item.second;
                    while (in_progress_status_count > 0 && task_count > 0)
                    {
                        ++update[TaskStatus::TESTING];
                        ++upgrade[TaskStatus::TESTING];
                        --in_progress_status_count;
                        --task_count;
                    }
                    if (in_progress_status_count > 0)
                    {
                    	untouch[TaskStatus::IN_PROGRESS] += in_progress_status_count;
                        upgrade[TaskStatus::IN_PROGRESS] += in_progress_status_count;
                    }
                }
            }
            if (item.first == TaskStatus::TESTING)
            {
                if (item.second > 0)
                {
                    int testing_status_count = item.second;
                    while (testing_status_count > 0 && task_count > 0)
                    {
                        ++update[TaskStatus::DONE];
                        ++upgrade[TaskStatus::DONE];
                        --testing_status_count;
                        --task_count;
                    }
                    if (testing_status_count > 0)
                    {
                    	untouch[TaskStatus::TESTING] += testing_status_count;
                        upgrade[TaskStatus::TESTING] += testing_status_count;
                    }
                }
            }
            if (item.first == TaskStatus::DONE)
            {
                if (item.second > 0)
                {
                    upgrade[TaskStatus::DONE] += item.second;
                }
            }
        }
        PersonTasks[person] = upgrade;
        return make_tuple(update, untouch);
    };

private:
    map<string, TasksInfo> PersonTasks;
};
