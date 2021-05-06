#include "AEntitySubject.h"


namespace csci3081
{

void AEntitySubject::Attach(IEntityObserver* observer) {
    observers.push_back(observer);
}

void AEntitySubject::Detach(IEntityObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void AEntitySubject::Notify(const picojson::value& event, const IEntity& entity) {
    for(IEntityObserver* observer : observers) {
        if (observer != NULL) {
            observer->OnEvent(event, entity);
        }
    }
}

}



