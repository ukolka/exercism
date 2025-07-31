namespace targets {
    class Alien {
        public:
            int x_coordinate{};
            int y_coordinate{};

            Alien(const int& x, const int& y) {
                teleport(x, y);
            }

            int get_health() {
                return health;
            }

            bool hit() {
                --health;
                if (health < 0) {
                    health = 0;
                }
                return true;
            }

            bool is_alive() {
                return health > 0;
            }

            bool teleport(const int& x, const int& y) {
                x_coordinate = x;
                y_coordinate = y;
                return true;
            }

            bool collision_detection(Alien other) {
                return other.x_coordinate == x_coordinate &&
                    other.y_coordinate == y_coordinate;
            }
        private:
            int health{3};
    };

}  // namespace targets