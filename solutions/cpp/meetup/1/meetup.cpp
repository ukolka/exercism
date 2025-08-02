#include "meetup.h"

namespace meetup {
    scheduler meetup_schedule(short unsigned month, short unsigned year) {
        return scheduler{month, year};
    }

    boost::gregorian::date scheduler::dotwteenth(boost::date_time::weekdays wd) const {
        boost::gregorian::date d{year, month, 13};
        while (d.day_of_week() != wd) {
            d += boost::gregorian::days(1);
        }
        return d;
    }

    boost::gregorian::date scheduler::nth_dotw(boost::date_time::weekdays wd, short unsigned n) const {
        if (n > 4 || n < 1) {
            throw std::domain_error("Expect 1 <= n <= 4.");
        }
        boost::gregorian::date d{year, month, 1};
        short unsigned count = 0;
        while (count < n) {
            if (d.day_of_week() == wd) {
                ++count;
                if (count == n) {
                    break;
                }
            }
            d += boost::gregorian::days(1);
        }
        return d;
    }

    boost::gregorian::date scheduler::last_dotw(boost::date_time::weekdays wd) const {
        boost::gregorian::date d{year, month, 1};
        boost::gregorian::date last{year, month, 1};
        while (d.month() == month) {
            if (d.day_of_week() == wd) {
                last = d;
            }
            d += boost::gregorian::days(1);
        }
        return last;
    }

    boost::gregorian::date scheduler::monteenth() const {
        return dotwteenth(boost::date_time::Monday);
    }

    boost::gregorian::date scheduler::tuesteenth() const {
        return dotwteenth(boost::date_time::Tuesday);
    }

    boost::gregorian::date scheduler::wednesteenth() const {
        return dotwteenth(boost::date_time::Wednesday);
    }

    boost::gregorian::date scheduler::thursteenth() const {
        return dotwteenth(boost::date_time::Thursday);
    }

    boost::gregorian::date scheduler::friteenth() const {
        return dotwteenth(boost::date_time::Friday);
    }

    boost::gregorian::date scheduler::saturteenth() const {
        return dotwteenth(boost::date_time::Saturday);
    }   

    boost::gregorian::date scheduler::sunteenth() const {
        return dotwteenth(boost::date_time::Sunday);
    }

    boost::gregorian::date scheduler::first_monday() const {
        return nth_dotw(boost::date_time::Monday, 1);
    }

    boost::gregorian::date scheduler::first_tuesday() const {
        return nth_dotw(boost::date_time::Tuesday, 1);
    }

    boost::gregorian::date scheduler::first_wednesday() const {
        return nth_dotw(boost::date_time::Wednesday, 1);
    }

    boost::gregorian::date scheduler::first_thursday() const {
        return nth_dotw(boost::date_time::Thursday, 1);
    }

    boost::gregorian::date scheduler::first_friday() const {
        return nth_dotw(boost::date_time::Friday, 1);
    }

    boost::gregorian::date scheduler::first_saturday() const {
        return nth_dotw(boost::date_time::Saturday, 1);
    }

    boost::gregorian::date scheduler::first_sunday() const {
        return nth_dotw(boost::date_time::Sunday, 1);
    }

    boost::gregorian::date scheduler::second_monday() const {
        return nth_dotw(boost::date_time::Monday, 2);
    }

    boost::gregorian::date scheduler::second_tuesday() const {
        return nth_dotw(boost::date_time::Tuesday, 2);
    }

    boost::gregorian::date scheduler::second_wednesday() const {
        return nth_dotw(boost::date_time::Wednesday, 2);
    }

    boost::gregorian::date scheduler::second_thursday() const {
        return nth_dotw(boost::date_time::Thursday, 2);
    }

    boost::gregorian::date scheduler::second_friday() const {
        return nth_dotw(boost::date_time::Friday, 2);
    }

    boost::gregorian::date scheduler::second_saturday() const {
        return nth_dotw(boost::date_time::Saturday, 2);
    }

    boost::gregorian::date scheduler::second_sunday() const {
        return nth_dotw(boost::date_time::Sunday, 2);
    }

    boost::gregorian::date scheduler::third_monday() const {
        return nth_dotw(boost::date_time::Monday, 3);
    }

    boost::gregorian::date scheduler::third_tuesday() const {
        return nth_dotw(boost::date_time::Tuesday, 3);
    }

    boost::gregorian::date scheduler::third_wednesday() const {
        return nth_dotw(boost::date_time::Wednesday, 3);
    }

    boost::gregorian::date scheduler::third_thursday() const {
        return nth_dotw(boost::date_time::Thursday, 3);
    }

    boost::gregorian::date scheduler::third_friday() const {
        return nth_dotw(boost::date_time::Friday, 3);
    }

    boost::gregorian::date scheduler::third_saturday() const {
        return nth_dotw(boost::date_time::Saturday, 3);
    }

    boost::gregorian::date scheduler::third_sunday() const {
        return nth_dotw(boost::date_time::Sunday, 3);
    }

    boost::gregorian::date scheduler::fourth_monday() const {
        return nth_dotw(boost::date_time::Monday, 4);
    }

    boost::gregorian::date scheduler::fourth_tuesday() const {
        return nth_dotw(boost::date_time::Tuesday, 4);
    }

    boost::gregorian::date scheduler::fourth_wednesday() const {
        return nth_dotw(boost::date_time::Wednesday, 4);
    }

    boost::gregorian::date scheduler::fourth_thursday() const {
        return nth_dotw(boost::date_time::Thursday, 4);
    }

    boost::gregorian::date scheduler::fourth_friday() const {
        return nth_dotw(boost::date_time::Friday, 4);
    }

    boost::gregorian::date scheduler::fourth_saturday() const {
        return nth_dotw(boost::date_time::Saturday, 4);
    }

    boost::gregorian::date scheduler::fourth_sunday() const {
        return nth_dotw(boost::date_time::Sunday, 4);
    }   

    boost::gregorian::date scheduler::last_monday() const {
        return last_dotw(boost::date_time::Monday);
    }

    boost::gregorian::date scheduler::last_tuesday() const {
        return last_dotw(boost::date_time::Tuesday);
    }

    boost::gregorian::date scheduler::last_wednesday() const {
        return last_dotw(boost::date_time::Wednesday);
    }

    boost::gregorian::date scheduler::last_thursday() const {
        return last_dotw(boost::date_time::Thursday);
    }

    boost::gregorian::date scheduler::last_friday() const {
        return last_dotw(boost::date_time::Friday);
    }

    boost::gregorian::date scheduler::last_saturday() const {
        return last_dotw(boost::date_time::Saturday);
    }

    boost::gregorian::date scheduler::last_sunday() const {
        return last_dotw(boost::date_time::Sunday);
    }
}  // namespace meetup
