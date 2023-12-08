#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <optional>
#include <sstream>

//In-memory key-value database
class InMemoryDB {
private:
    //Main database storage
    std::unordered_map<std::string, int> main_db;

    //Temporary storage (uncommitted transactions)
    std::unordered_map<std::string, int> transaction_db;

    //Flag if a transaction is in progress
    bool in_transaction = false;

public:
    //Retrieves value of given key.
    std::optional<int> get(const std::string& key) {
        //Only return val of transaction_db if transaction is committed
        if (!in_transaction && main_db.find(key) != main_db.end()) {
            return main_db[key];
        }
        return std::nullopt;
    }


    //Inserts/updates the val for a given key. (exception if not in a transaction)
    void put(const std::string& key, int val) {
        if (!in_transaction) {
            throw std::runtime_error("No transaction in progress");
        }
        transaction_db[key] = val;
    }

    //Begins a new transaction
    void begin_transaction() {
        if (in_transaction) {
            throw std::runtime_error("Transaction already in progress");
        }
        in_transaction = true;
        transaction_db.clear();
    }

    //Commits the current transaction, applying changes to main database
    void commit() {
        if (!in_transaction) {
            throw std::runtime_error("No transaction in progress");
        }
        for (const auto& kv : transaction_db) {
            main_db[kv.first] = kv.second;
        }
        in_transaction = false;
        transaction_db.clear();
    }

    //Rolls back the current transaction, discarding all changes
    void rollback() {
        if (!in_transaction) {
            throw std::runtime_error("No transaction in progress");
        }
        in_transaction = false;
        transaction_db.clear();
    }
};

int main() {
    //InMemoryDB instance
    InMemoryDB db;
    std::string line;

    //Loop to read and process user input
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        //get command
        if (command == "get") {
            std::string key;
            iss >> key;
            auto value = db.get(key);
            if (value) {
                std::cout << *value << std::endl;
            } else {
                std::cout << "null" << std::endl;
            }
        }
            //put command
        else if (command == "put") {
            std::string key;
            int value;
            if (iss >> key >> value) {
                try {
                    db.put(key, value);
                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            }
        }
            //begin_transaction command
        else if (command == "begin_transaction") {
            try {
                db.begin_transaction();
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
            //commit command
        else if (command == "commit") {
            try {
                db.commit();
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
            //rollback command
        else if (command == "rollback") {
            try {
                db.rollback();
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else {
            std::cerr << "Unknown command." << std::endl;
        }
    }

    return 0;
}
