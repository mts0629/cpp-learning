#include <iostream>

int main () {
    int x = 5;

    // if statement
    if (x == 5) {
        std::cout << "x is five" << std::endl;
    } else if (x < 0) {
        std::cout << "x is negative" << std::endl;
    } else {
        std::cout << "x is " << x << std::endl;
    }

    // switch statement
    // The number of comparison will be lesser than if-else sequence
    switch (x) {
        case 0:
            std::cout << "x is zero" << std::endl;
            break;
        case 1:
            std::cout << "x is one" << std::endl;
            break;
        // Fall through
        case 2:
        case 3:
            std::cout << "x is two or three" << std::endl;
            break;
        default:
            std::cout << "x is " << x << std::endl;
            break;
    }

    bool done = false;

    // while
    while (!done) {
        x += (x - 3);

        std::cout << x << std::endl;

        if (x % 5 == 0) {
            done = true;
        }
    }

    x = 5;
    done = false;

    // do-while
    do {
        x += (x - 3);

        std::cout << x << std::endl;

        if (x % 5 == 0) {
            done = true;
        }
    } while (!done);

    // for
    for (int i = 0; i < 10; ++i) {
        std::cout << i << std::endl;
    }

    x = 5;

    // break
    while (true) {
        x += (x - 3);

        std::cout << x << std::endl;

        if (x % 5 == 0) {
            break;
        }
    }

    // break in nested loop
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                break;
            }

            std::cout << i << ", " << j << std::endl;
        }
    }

    // continue
    for (int i = 0; i < 10; ++i) {
        if (i == 5) {
            continue;
        }

        std::cout << i << std::endl;
    }

    // continue in nested loop
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                continue;
            }

            std::cout << i << ", " << j << std::endl;
        }
    }

    // continue in do-while
    do {
        std::cout << "done" << std::endl;
        continue; // Skip and go to a loop condition

        std::cout << "never reached here" << std::endl;
    } while (false); // Finish with only one execution

    return 0;
}
