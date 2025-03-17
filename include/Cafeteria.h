#ifndef CAFETERIA_H
#define CAFETERIA_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Dish {
private:
    std::string name;
    std::vector<std::string> ingredients;
    float spiceLevel;
    std::string type;
    float price;
    bool isAvailable;
    std::vector<float> ratings;

public:
    Dish(std::string name, std::vector<std::string> ingredients, float spiceLevel, std::string type, float price, bool isAvailable = true);
    ~Dish();

    void setName(std::string val) { name = val; }
    std::string getName() { return name; }

    void setIngredients(std::vector<std::string> &val) { ingredients = val; }
    void getIngredients();

    void setSpice(float val) { spiceLevel = val; }
    float getSpiceLevel() { return spiceLevel; }

    void setType(std::string val) { type = val; }
    std::string getType() { return type; }

    void setPrice(float val) { price = val; }
    float getPrice() { return price; }

    void setAvailability(bool val) { isAvailable = val; }
    bool getAvailability() { return isAvailable; }

    void addRating(float rating);
    float getAverageRating();

    void displayDish();
};

enum MealType {
    BREAKFAST,
    LUNCH,
    DINNER,
    SNACK
};

class Cafeteria {
private:
    std::vector<Dish> menu;
    MealType mealType;

public:
    Cafeteria(MealType mealType);
    ~Cafeteria();

    void addDish(const Dish& dish);
    void removeDish(const std::string& dishName);
    Dish* findDish(const std::string& dishName);
    void filterMenuByType(const std::string& type);
    void displayCafe();
};

class CafeteriaManager {
private:
    Cafeteria cafeteria;
    std::vector<std::string> orders;

public:
    CafeteriaManager(MealType mealType);
    void placeOrder(const std::string& dishName);
    void cancelOrder(const std::string& dishName);
    void viewOrders();
};

enum PaymentMethod {
    CASH,
    CARD,
    DIGITAL
};

class Payment {
private:
    float amount;
    PaymentMethod method;
    bool isPaid;

public:
    Payment(float amount, PaymentMethod method);
    void processPayment();
};

#endif // CAFETERIA_H






