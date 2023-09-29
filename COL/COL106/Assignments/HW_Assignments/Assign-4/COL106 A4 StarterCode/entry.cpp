/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "entry.h"

SymEntry::SymEntry()
{
    left = nullptr;
    right = nullptr;
    key = "";
    val = new UnlimitedRational();
}

SymEntry::SymEntry(string k, UnlimitedRational* v)
{
    left = nullptr;
    right = nullptr;
    key = k;
    val = new UnlimitedRational(v->get_p(), v->get_q());
}

SymEntry::~SymEntry()
{
    delete val;
}