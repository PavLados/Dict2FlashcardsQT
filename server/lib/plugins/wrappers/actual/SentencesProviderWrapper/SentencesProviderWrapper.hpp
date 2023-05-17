#ifndef SENTENCES_PROVIDER_WRAPPER_H
#define SENTENCES_PROVIDER_WRAPPER_H

#include <concepts>
#include <cstdint>
#include <nlohmann/json_fwd.hpp>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "BasePluginWrapper.hpp"
#include "ISentencesProviderWrapper.hpp"
#include "PyExceptionInfo.hpp"

class SentencesProviderWrapper : public BasePluginWrapper,
                                 public ISentencesProviderWrapper {
 public:
    SentencesProviderWrapper(const SentencesProviderWrapper &other);
    SentencesProviderWrapper(SentencesProviderWrapper &&) = default;
    auto operator=(const SentencesProviderWrapper &)
        -> SentencesProviderWrapper & = delete;
    auto operator=(SentencesProviderWrapper &&)
        -> SentencesProviderWrapper & = default;

    static auto build(const std::string           &name,
                      const boost::python::object &module)
        -> std::variant<SentencesProviderWrapper, PyExceptionInfo>;

    auto get(const std::string &word, uint64_t batch_size)
        -> std::variant<ISentencesProviderWrapper::type, PyExceptionInfo>;

 protected:
    struct SentencesProvidersFunctions {
        static auto build(const boost::python::object &module)
            -> std::variant<SentencesProvidersFunctions, PyExceptionInfo>;

        boost::python::object get;
    };

    SentencesProvidersFunctions specifics_;

 private:
    explicit SentencesProviderWrapper(BasePluginWrapper &&base);
};

static_assert(is_plugin_wrapper<SentencesProviderWrapper>);

#endif