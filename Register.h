//
// Created by Sofia Galante on 22/06/19.
//

#ifndef ACTIVITYTRACKER_REGISTER_H
#define ACTIVITYTRACKER_REGISTER_H

#include "Activity.h"
#include "Subject.h"
#include <map>
#include <list>
#include <iostream>

class Register : public Subject {
public:

    unsigned long coutDateActivities(std::string date) const{
        return logbook.count(date);
    }
    void saveActivity(const Activity &activity);
    void printDateActivities(const std::string &date);
    void printAllActivities();

    std::multimap<std::string, Activity>::iterator begin(){
        return logbook.begin();
    }
    std::multimap<std::string, Activity>::iterator end(){
        return logbook.end();
    }

    virtual void subscribe(Observer * o) override;
    virtual void unsubscribe(Observer * o) override;
    virtual void notify() override;

private:
    std::multimap<std::string, Activity> logbook;
    std::list<Observer *> observers;
};

#endif //ACTIVITYTRACKER_REGISTER_H
