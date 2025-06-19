#include "task.h"

Task::Task() {}


Task::Task(std::string title, std::string description, TaskCategory taskCategory, TaskType taskType)
{
    this->title = title;
    this->description = description;
    this->taskCategory = taskCategory;
    this->taskType = taskType;
}


std::string Task::getTitle() const {
    return title;
}

std::string Task::getDescription() const {
    return description;
}

TaskCategory Task::getTaskCategory() const {
    return taskCategory;
}

TaskType Task::getTaskType() const {
    return taskType;
}


std::string Task::getImagePath() const {
    return imagePath;
}

void Task::setTitle(const std::string& title) {
    this->title = title;
}

void Task::setDescription(const std::string& description) {
    this->description = description;
}

void Task::setTaskCategory(TaskCategory taskCategory) {
    this->taskCategory = taskCategory;
}

void Task::setTaskType(TaskType taskType) {
    this->taskType = taskType;
}

void Task::setImagePath(const std::string& imagePath) {
    this->imagePath = imagePath;
}
