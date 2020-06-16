#include <iostream>
#include <string>

class Ship {
   public:
    Ship() : id_(-1) {}
    Ship(size_t id, const std::string& name, size_t speed, size_t max_crew, size_t capacity)
        : id_(id), name_(name), speed_(speed), maxCrew_(max_crew), capacity_(capacity) {}
    Ship(size_t id, size_t speed, size_t max_crew) : Ship(id, "", speed, max_crew, 0) {}

    void set_name(const std::string& name) { name_ = name; }

    Ship& operator+=(const int number) {
        if (crew_ + number <= maxCrew_) {
            crew_ += number;
        }
        std::cerr << "Too many marynarzy!";
        return *this;
    }

    Ship& operator+=(const int number) {
        if (crew_ >= number) {
            crew_ -= number;
        }
        std::cerr << "Too less marynarzy!";
        return *this;
    }

    size_t getId() const { return id_; }
    std::string getName() const { return name_; }
    size_t getSpeed() const { return speed_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getCapacity() const { return capacity_; }

   private:
    size_t id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
};
