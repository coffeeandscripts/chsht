/* chsht - console cheatsheet viewer
 * manager.cpp
 * desc: functions to manipulate chsht files
 * vers: 0.0.1
 */

#include <iostream>
#include <fstream>
#include <cstring>

#include "manager.hpp"
#include "setup.hpp"

#define SYSTEM_ERROR 256

/* class - Manager constructor
 * desc: allocates memory to store console arguments
 */
Manager::Manager (char *n, Setup s_engine) {
        input = n;
        sheet_dir = s_engine.read_conf("directory");
        title = 0;
        cmd = '\0';
        n_cmd = 0;
        indent = 0;
        new_line = true;
}

/* class - Manager deconstructor
 * desc: currently clear but open to memory clearing to prevent memory leaks
 */
Manager::~Manager() {
}

void Manager::print_cmd(char cmd) {
        switch(cmd) {
                case 'y':
                        std::cout << "[33m";
                        break;
                case 'b':
                        std::cout << "[34m";
                        break;
                case 'g':
                        std::cout << "[32m";
                        break;
                case 'c':
                        std::cout << "[36m";
                        break;
                case 'p':
                        std::cout << "[35m";
                        break;
                case 's':
                        std::cout << "[01m";
                        break;
                case '1':
                        std::cout << "[01m";
                        break;
                case '2':
                        std::cout << "[33m";
                        indent = 2;
                        break;
                case '3':
                        std::cout << "[32m";
                        indent = 4;
                        break;
        }
}

/* func - cls_hl()
 * desc: closes the highlight function
*/
void Manager::cls_hl() {
        std::cout << "[0m";
        switch(cmd) {
                case '2':
                        indent = 4;
                        break;
                case '3':
                        indent = 6;
                        break;
        }
}

void Manager::new_line_indent() {
        switch(indent) {
                case 0:
                        break;
                case 2:
                        std::cout << "  ";
                        break;
                case 4:
                        std::cout << "    ";
                        break;
                case 6:
                        std::cout << "      ";
                default:
                        break;
        }
}

void Manager::mode_set(char ch) {
        if (ch == '\\' && n_cmd == 0) {
                cmd = '=';
                n_cmd++;
        } else if (n_cmd == 0) {
                switch(ch) {
                        case '\n':
                                cls_hl();
                                cmd = '\0';
                                n_cmd = 0;
                                std::cout << std::endl;
                                new_line = true;
                                break;
                        case '(':
                                print_cmd('p');
                                break;
                        case ')':
                                cls_hl();
                                std::cout << " -- ";
                                break;
                        case '[':
                                print_cmd('s');
                                break;
                        case ']':
                                cls_hl();
                                break;
                        default:
                                if (new_line) {
                                        new_line_indent();
                                }
                                std::cout << ch;
                                new_line = false;
                                break;
                }
        } else if (ch == '\\' && n_cmd == 1) {
                std::cout << ch;
                cmd = '\0';
                n_cmd = 0;
        } else if (n_cmd == 1 && ch == '/') {
                cls_hl();
                cmd = '\0';
                n_cmd = 0;
        } else if (n_cmd == 1) {
                print_cmd(ch);
                cmd = ch;
                n_cmd = 0;
        }
}

void Manager::interpret_file() {
        std::ifstream fin;
        fin.open("docs/default.chsht", std::ios::in);
        char ch;
        while (!fin.eof() ) {
        	fin.get(ch);
        	mode_set(ch);
	}
}

/* function -
 * desc:
 */
void Manager::print() {
        char buf[BUFSIZ];
        interpret_file();
        snprintf(buf ,sizeof(buf), "less -FX .\\/docs\\/sheets\\/%s.chsht 2>/dev/null", input);
        if (system(buf)== SYSTEM_ERROR){
            std::cout << "File does not exist. Type -h for help" << std::endl;
        }
}

/* function -
 * desc:
 */
int Manager::checkFile(){
        char buf[BUFSIZ];
        snprintf(buf ,sizeof(buf), "[ -f \"./docs/sheets/%s.chsht\" ] && echo 1 || echo 0", input);
        int check_default = stoi(terminal_stdout(buf));
        if( check_default == 1 ){
                std::cout << "File Exists" << std::endl;
                return 1;
        }else {
                std::cout <<" File Does Not Exist" << std::endl;
                return 0;
        }
}
