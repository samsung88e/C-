/**
 *@file entity_base.h
 */
#ifndef ENTITY_BASE_H_
#define ENTITY_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include "AEntitySubject.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base class for creating entities.
 *
 * This class can be used as the base for all entities in the delivery system.
 * The overall design is up to you (the student), but all entities must implement
 * the IEntity interface.
 *
 * See the documentation for IEntity for more information
 */

class EntityBase : public IEntity {
 public:
  virtual ~EntityBase() {}
 
  const picojson::object& GetDetails() { return details_; }
  
  /**
  Returns the ID of the entity. 
  To give a specific number of ID to each subject.
  */
  int GenerateId() {
    static int next_id = 0;
    next_id++;
    return next_id;
  }

  /**
  * Returns the ID of the entity.
  */
  int GetId() const{ return id; };

  /**
  * Returns the Name of the entity.
  */
  const std::string& GetName(){ return name; };

  /**
  * Returns the current position of the entity.
  */
  const std::vector<float>& GetPosition() const{ return position; };
  
  /**
  * Returns the current direction of the entity.
  */
  const std::vector<float>& GetDirection() const{ return direction; };

  /**
  * Returns the radius of the entity.
  */
  float GetRadius() const{ return radius; };

  /**
  * Returns the Version of the entity (Not yet implemeted).
  */
  int GetVersion() const{ return version; };
  
  /**
   * Return whether the entity is dynamic
   */
   bool IsDynamic() const{ return is_dynamic; };
   
   /**
   * Set the id for the object.
   */
  void SetId(int id);
  
  /**
   * Set the name of the object.
   */
  void SetName(std::string name);
  
  /**
   * Set the current position of the object in the simulation.
   */
  void SetPosition(std::vector<float>& position);
  
  /**
   * Set the current position of the object in the simulation.
   */
  void SetDirection(std::vector<float>& direction);
  
  /**
   * Get the radius around the object.
   */
  void SetRadius(float radius);
  
  /**
   * Set the version of the object.
   */
  void SetVersion(int version);
  
  /**
   * Set whether the object is dynamic in the simulation.
   */
  void SetDynamic(bool dynamic);

  /**
   * Set the subject to check the deliverer in the simulation.
   */
  void SetEntitySubject(AEntitySubject* sub) {
    entitySubject = sub;
  }

  /**
   * Check whether the object is deliverer in the simulation.
   */
  bool IsDeliverer() {
    return false;
  }

 protected:

  // protected variables to be implemented in the inheritanced class.
  picojson::object details_;
  int id;
  std::string name;
  std::vector<float> position{0.f,0.f,0.f};
  std::vector<float> direction{0.f,0.f,0.f};
  float radius;
  int version;
  bool is_dynamic;
  AEntitySubject* entitySubject;
  
};

}  // namespace csci3081

#endif  // ENTITY_BASE_H_
