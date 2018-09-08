/* chsht - console cheatsheet viewer
 * setup.hpp
 * desc: header for setup engine class
 * vers: 0.0.1
 */

#ifndef PROJECT_SETUP_
#define PROJECT_SETUP_

class Setup {
private:
public:
        Setup();
        ~Setup();
        int exists(char const *);
        int run();
        void reset();
        char const *read_conf(char const *);
};

#endif
