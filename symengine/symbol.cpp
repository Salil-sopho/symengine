#include <symengine/constants.h>
#include <symengine/symengine_casts.h>

namespace SymEngine
{

Symbol::Symbol(const std::string &name) : name_{name}
{
    SYMENGINE_ASSIGN_TYPEID()
}

hash_t Symbol::__hash__() const
{
    hash_t seed = 0;
    hash_combine(seed, name_);
    return seed;
}

bool Symbol::__eq__(const Basic &o) const
{
    if (is_a<Symbol>(o))
        return name_ == down_cast<const Symbol &>(o).name_;
    return false;
}

int Symbol::compare(const Basic &o) const
{
    SYMENGINE_ASSERT(is_a<Symbol>(o))
    const Symbol &s = down_cast<const Symbol &>(o);
    if (name_ == s.name_)
        return 0;
    return name_ < s.name_ ? -1 : 1;
}

} // SymEngine
