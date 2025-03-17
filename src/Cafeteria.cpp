#include "Cafeteria.h"

Dish::Dish(std::string name, std::vector<std::string> ingredients, float spiceLevel, std::string type, float price, bool isAvailable)
    : name(name), ingredients(ingredients), spiceLevel(spiceLevel), type(type), price(price), isAvailable(isAvailable) {}

Dish::~Dish() {}



/*void Dish::displayDish(){
    std::cout << "Dish: " << name << "\nIngredients: ";
    for(auto it:ingredients){
        std::cout << it << ", ";
    }
    std::cout << std::endl;
    std::cout <<  "Type: " << type << "\nSpice Level: " << spiceLevel << "\nPrice: Tk" << price << (isAvailable?"\nAvailable":"\nNot Available") << std::endl;
}*/


void Dish::displayDish()
{
    std::cout << "========================================\n";
    std::cout << "              Dish Details              \n";
    std::cout << "========================================\n";
    std::cout << " Dish Name    : " << name << "\n";

    std::cout << " Ingredients  : ";
    for (size_t i = 0; i < ingredients.size(); ++i)
    {
        std::cout << ingredients[i];
        if (i < ingredients.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "\n";

    std::cout << " Type         : " << type << "\n";
    std::cout << " Spice Level  : " << spiceLevel << "\n";
    std::cout << " Price        : Tk " << price << "\n";
    //std::cout << " Availability : " << (isAvailable ? "Available" : "Not Available") << "\n";
    std::cout << "========================================\n";
}



void Dish::addRating(float rating)
{
    ratings.push_back(rating);
}

float Dish::getAverageRating()
{
    if (ratings.empty()) return 0.0f;
    float sum = 0;
    for (float r : ratings) sum += r;
    return sum / ratings.size();
}

Cafeteria::Cafeteria(MealType mealType) : mealType(mealType) {}

Cafeteria::~Cafeteria() {}

void Cafeteria::addDish(const Dish& dish)
{
    menu.push_back(dish);
}

void Cafeteria::removeDish(const std::string& dishName)
{
    menu.erase(std::remove_if(menu.begin(), menu.end(), [&](Dish& d)
    {
        return d.getName() == dishName;
    }), menu.end());
}

Dish* Cafeteria::findDish(const std::string& dishName)
{
    for (Dish& dish : menu)
    {
        if (dish.getName() == dishName) return &dish;
    }
    return nullptr;
}

void Cafeteria::filterMenuByType(const std::string& type)
{
    for (Dish& dish : menu)
    {
        if (dish.getType() == type)
        {
            dish.displayDish();
        }
    }
}

void Cafeteria::displayCafe()
{
    for (Dish& dish : menu)
    {
        dish.displayDish();
    }
}

CafeteriaManager::CafeteriaManager(MealType mealType) : cafeteria(mealType) {}

void CafeteriaManager::placeOrder(const std::string& dishName)
{
    if (cafeteria.findDish(dishName)) orders.push_back(dishName);
}

void CafeteriaManager::cancelOrder(const std::string& dishName)
{
    orders.erase(std::remove(orders.begin(), orders.end(), dishName), orders.end());
}

void CafeteriaManager::viewOrders()
{
    for (const std::string& order : orders)
    {
        std::cout << "Order: " << order << std::endl;
    }
}

Payment::Payment(float amount, PaymentMethod method) : amount(amount), method(method), isPaid(false) {}

void Payment::processPayment()
{
    isPaid = true;
    std::cout << "Payment of Tk" << amount << " processed via " << (method == CASH ? "Cash" : method == CARD ? "Card" : "Digital") << std::endl;
}
