//
// Created by Henrique on 29/06/2025.
//

#ifndef UTILS_HPP
#define UTILS_HPP


#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
inline void limparTela() {
    system(CLEAR);
}

#endif // UTILS_HPP
