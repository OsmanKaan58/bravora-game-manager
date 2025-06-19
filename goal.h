#ifndef GOAL_H
#define GOAL_H
#include <string>
#include "goalpriority.h"
#include "taskcategory.h"
class Goal
{
public:
    Goal();
    Goal(const std::string& goalTitle, const std::string& goalDescription,
         GoalPriority priorityDegree, TaskCategory category); // All-args constructor


    std::string getGoalTitle() const;
    std::string getGoalDescription() const;
    GoalPriority getPriorityDegree() const;
    TaskCategory getCategory() const;


    void setGoalTitle(const std::string& goalTitle);
    void setGoalDescription(const std::string& goalDescription);
    void setPriorityDegree(GoalPriority priorityDegree);
    void setCategory(TaskCategory category);
private:
    std::string goalTitle;
    std::string goalDescription;
    GoalPriority priorityDegree;
    TaskCategory category;
};

#endif // GOAL_H
