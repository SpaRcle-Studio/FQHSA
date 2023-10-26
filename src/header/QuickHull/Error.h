/**
 * Author:    Andrea Casalino
 * Created:   06.01.2020
 *
 * report any bug to andrecasa91@gmail.com.
 **/

#ifndef QH_ERROR_H
#define QH_ERROR_H

#include <stdexcept>

namespace qh {
    class Error : public std::runtime_error {
    public:
        explicit Error(const std::string &what) : std::runtime_error(what){};
    };
} // namespace qh

#endif //QH_ERROR_H