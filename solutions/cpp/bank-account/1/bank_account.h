#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H
#include <stdexcept>
#include <atomic>
using namespace std;

namespace Bankaccount {
    class Bankaccount {
    private:
        atomic<int> balance_{};
        atomic<bool> is_open;
    public:
        Bankaccount() : balance_(0), is_open(false) {}

        void is_valid() {
            if (!is_open.load()) throw runtime_error("Expecting an open account");
        }

        void open() {
            if (is_open.load()) throw runtime_error("Expecting a non-open account");
            is_open.exchange(true);
        }

        void close() {
            is_valid();
            is_open.store(false);
            balance_.store(0);
        }

        int balance() {
            is_valid();
            return balance_.load();
        }

        void deposit(int amt) {
            is_valid();
            int new_balance = amt + balance_.load();
            if (new_balance < 0) throw runtime_error("Expecting sufficient funds.");
            balance_.store(new_balance);
        }

        void withdraw(int amt) {
            if (amt < 0) throw runtime_error("Expect a positive amount.");
            deposit(-amt);
        }

    };  // class Bankaccount

}  // namespace Bankaccount

#endif  // BANK_ACCOUNT_H