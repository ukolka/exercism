#include <stdlib.h>
#include <string.h>
#include "grade_school.h"


void init_roster(roster_t* roster) {
    roster->count = 0;
}

void init_student(student_t* student, uint8_t grade, const char* name) {
    student->grade = grade;
    unsigned int len = strlen(name);
    memcpy(student->name, name, len);
    student->name[len] = '\0';
}

int studentCmp(const void* a, const void* b) {
    student_t* aP = (student_t*) a;
    student_t* bP = (student_t*) b;

    int gradeCmp = aP->grade - bP->grade;

    if (gradeCmp != 0) {
        return gradeCmp;
    }

    unsigned int aNameLen = strlen(aP->name);
    unsigned int bNameLen = strlen(bP->name);

    unsigned int lenToCmp = aNameLen;
    if (aNameLen > bNameLen) {
        lenToCmp = bNameLen;
    }
    return memcmp(aP->name, bP->name, lenToCmp);
}

bool add_student(
    roster_t* roster,
    const char* name,
    uint8_t grade) {
        unsigned int nameLen = strlen(name);
        for (size_t i = 0; i < roster->count; i++) {
            if (memcmp(roster->students[i].name, name, nameLen) == 0) {
                return false;
            }
        }

        student_t student;
        init_student(&student, grade, name);

        roster->students[roster->count++] = student;

        int (*cmpStudent)(const void *, const void *) = &studentCmp;

        qsort(roster->students,
            roster->count,
            sizeof(student_t),
            cmpStudent);

        return true;
}

roster_t get_grade(roster_t* roster, uint8_t grade) {
    roster_t retRoster;
    init_roster(&retRoster);

    student_t* student;

    for (size_t i = 0; i < roster->count; i++) {
        student = &roster->students[i];
        if (grade == student->grade) {
            add_student(
                &retRoster,
                student->name,
                grade);

        }
    }

    return retRoster;
}