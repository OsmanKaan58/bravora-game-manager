#include "goal.h"


Goal::Goal() {}


Goal::Goal(const std::string& goalTitle, const std::string& goalDescription,
           GoalPriority priorityDegree, TaskCategory category)
{
    this->goalTitle = goalTitle;
    this->goalDescription = goalDescription;
    this->priorityDegree = priorityDegree;
    this->category = category;
}


std::string Goal::getGoalTitle() const {
    return goalTitle;
}

std::string Goal::getGoalDescription() const {
    return goalDescription;
}

GoalPriority Goal::getPriorityDegree() const {
    return priorityDegree;
}

TaskCategory Goal::getCategory() const {
    return category;
}


void Goal::setGoalTitle(const std::string& goalTitle) {
    this->goalTitle = goalTitle;
}

void Goal::setGoalDescription(const std::string& goalDescription) {
    this->goalDescription = goalDescription;
}

void Goal::setPriorityDegree(GoalPriority priorityDegree) {
    this->priorityDegree = priorityDegree;
}

void Goal::setCategory(TaskCategory category) {
    this->category = category;
}
