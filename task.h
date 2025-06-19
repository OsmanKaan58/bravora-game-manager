#ifndef TASK_H
#define TASK_H
#include <string>
#include "tasktype.h"
#include "taskcategory.h"
class Task
{
public:
    Task();
    Task(std::string title, std::string description, TaskCategory taskCategory, TaskType taskType);
    std::string getTitle() const;
    std::string getDescription() const;
    TaskCategory getTaskCategory() const;
    TaskType getTaskType() const;
    std::string getImagePath() const;
    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setTaskCategory(TaskCategory taskCategory);
    void setTaskType(TaskType taskType);
    void setImagePath(const std::string& imagePath);
private:
    std::string title;
    std::string description;
    TaskCategory taskCategory;
    TaskType taskType;
    std::string imagePath;
};

#endif // TASK_H
