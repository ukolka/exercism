namespace hellmath {

enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

enum class Action {
    read,
    write,
    remove
};

bool display_post(AccountStatus poster, AccountStatus viewer) {
    return poster != AccountStatus::troll || viewer == poster;
}

bool permission_check(Action action, AccountStatus user) {
    switch (action) {
        case (Action::remove):
            return user == AccountStatus::mod;
        case (Action::write):
            return user != AccountStatus::guest;
        case (Action::read):
            return true;
        default:
            return false;
    }
}

bool valid_player_combination(AccountStatus p1, AccountStatus p2) {
    if (p1 > p2) {
        return valid_player_combination(p2, p1 );
    }
    return p1 > AccountStatus::guest || (p1 == p2 && p1 == AccountStatus::troll);
}

bool has_priority(AccountStatus p1, AccountStatus p2) {
    return p1 > p2;
}


}