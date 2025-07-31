#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H
#include <memory>
using namespace std;

namespace binary_search_tree {
    template<typename T>
    class binary_tree {
    private:
        T data_;
        binary_tree<T>* parent_;
        unique_ptr<binary_tree<T>> left_;
        unique_ptr<binary_tree<T>> right_;
    public:
        binary_tree(const T& data) : 
            data_(data),
            parent_(nullptr),
            left_(nullptr),
            right_(nullptr) {}

        const T& data() const {
            return data_;
        }
    
        const std::unique_ptr<binary_tree<T>>& left() const {
            return left_;
        }
    
        const std::unique_ptr<binary_tree<T>>& right() const {
            return right_;
        }

        void insert(const T& data) {
            auto& branch = data <= data_ ? left_ : right_;
            if (branch == nullptr) {
                branch = unique_ptr<binary_tree<T>>(new binary_tree<T>(data));
                branch.get()->parent_ = this;
            } else {
                branch->insert(data);
            }
        }

        class iterator {
        private:
            binary_tree<T>* node_;

        public:
            iterator(binary_tree* node) {
                node_ = node;
                if (node_ != nullptr) {
                    while (node_->left_ != nullptr) {
                        node_ = node_->left_.get();
                    }
                }
            }

            T& operator*() const {
                return node_->data_;
            }

            iterator& operator++() {
                if (node_->right_ != nullptr) {
                    node_ = node_->right_.get();
                    while (node_->left_ != nullptr) {
                        node_ = node_->left_.get();
                    }
                } else {
                    auto parent = node_->parent_;
                    while (parent != nullptr && node_ == parent->right_.get()) {
                        node_ = parent;
                        parent = parent->parent_;
                    }
                    node_ = parent;
                }
                return *this;
            }
            bool operator!=(const iterator& other) const {
                return node_ != other.node_;
            }
        };

        iterator begin() {
            return iterator(this);
        }

        iterator end() {
            return iterator(nullptr);
        }
    };
}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H