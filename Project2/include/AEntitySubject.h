#ifndef A_ENTITY_SUBJECT_H_
#define A_ENTITY_SUBJECT_H_
#include <EntityProject/facade/delivery_system.h>


namespace csci3081
{
class AEntitySubject {
    public:
        void Attach(IEntityObserver* observer);
        void Detach(IEntityObserver* observer);
        void Notify(const picojson::value& event, const IEntity& entity);
    private:
        std::vector<IEntityObserver*> observers;
};
}


#endif