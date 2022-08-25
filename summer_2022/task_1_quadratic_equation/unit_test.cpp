#include "unit_test.h"
#include "solver.h"


void Test() {
    FILE *test_cases_fp = fopen(
            R"(..\summer_2022\task_1_quadratic_equation\test_cases.txt)", "r");
    FILE *test_cases_answers_fp = fopen(
            R"(..\summer_2022\task_1_quadratic_equation\test_cases_answers.txt)", "r");

    Coefficients test_case;
    Answers test_case_answers;
    Roots roots;
    int ok_test = 0;
    int tests_amount = 0;

    if (test_cases_fp != nullptr) {
        while (fscanf(test_cases_fp, "%lg, %lg, %lg", &test_case.a, &test_case.b, &test_case.c) != EOF) {
            fscanf(test_cases_answers_fp, "%d, %lg, %lg",
                   &test_case_answers.roots_amount, &test_case_answers.x1, &test_case_answers.x2);

            RootsAmount roots_amount = SolveEquation(test_case.a, test_case.b, test_case.c, &roots.x1, &roots.x2);

            ok_test += TestResult(roots_amount, roots, test_case_answers);
            tests_amount++;
        }
        fclose(test_cases_fp);
    } else {
        perror(R"(..\summer_2022\task_1_quadratic_equation\test_cases.txt)");
    }

    system(("chcp"s).c_str());
    printf("\x1B[32m" "%d tests PASSED out of %d\n" "\x1B[0m", ok_test, tests_amount, "\x1B[37m");
}

bool TestResult(const RootsAmount roots_amount, const Roots roots, const Answers test_case_answers) {
    switch (roots_amount) {
        case ONE_ROOT: {
            bool correct_answer =
                    (roots_amount == test_case_answers.roots_amount && IsEqual(roots.x1, test_case_answers.x1));
            assert(correct_answer);
            if (!(correct_answer)) {
                printf("FAILED:   number of roots = %s, x = %lg\n"
                       "EXPECTED: number of roots = %s, x = %lg\n",
                       ROOT_NUMBERS_NAMES[roots_amount], roots.x1,
                       ROOT_NUMBERS_NAMES[test_case_answers.roots_amount], test_case_answers.x1);
            } else {
                printf("PASSED\n");
                return true;
            }
            break;
        }
        case TWO_ROOTS: {
            bool correct_answer =
                    ((TWO_ROOTS == test_case_answers.roots_amount) &&
                     (
                             (IsEqual(roots.x1, test_case_answers.x1) && IsEqual(roots.x2, test_case_answers.x2)) ||
                             (IsEqual(roots.x1, test_case_answers.x2) && IsEqual(roots.x2, test_case_answers.x1))
                     ));
            assert(correct_answer);
            if (!(correct_answer)) {
                printf("FAILED:   number of roots = %s, x1 = %lg, x2 = %lg\n"
                       "EXPECTED: number of roots = %s, x1 = %lg, x2 = %lg\n",
                       ROOT_NUMBERS_NAMES[roots_amount], roots.x1, roots.x2,
                       ROOT_NUMBERS_NAMES[test_case_answers.roots_amount], test_case_answers.x1, test_case_answers.x2);
            } else {
                printf("PASSED\n");
                return true;
            }
            break;
        }
        default:
            bool correct_answer = (NO_ROOTS == test_case_answers.roots_amount ||
                                   INFINITY_ROOTS == test_case_answers.roots_amount ||
                                   IMAGINARY_ROOTS == test_case_answers.roots_amount);
            assert(correct_answer);
            if (!(correct_answer)) {
                printf("FAILED:   number of roots = %s\n"
                       "EXPECTED: number of roots = %s\n",
                       ROOT_NUMBERS_NAMES[roots_amount],
                       ROOT_NUMBERS_NAMES[test_case_answers.roots_amount]);
            } else {
                printf("PASSED\n");
                return true;
            }
            break;
    }
    return false;
}