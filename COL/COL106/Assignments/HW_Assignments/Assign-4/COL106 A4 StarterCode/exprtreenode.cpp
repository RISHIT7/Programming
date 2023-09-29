/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"

ExprTreeNode::ExprTreeNode()
{
    type = "";
    val = new UnlimitedRational();
    evaluated_value = new UnlimitedRational();
    id = "";
    left = nullptr;
    right = nullptr;
}

ExprTreeNode::ExprTreeNode(string t, UnlimitedInt *v) // maybe wrong
{
    type = t;
    if (t == "VAR" || t == "VAL")
    {
        UnlimitedInt *one = new UnlimitedInt(1);
        val = new UnlimitedRational(v, one);
        evaluated_value = val; // temp
        id = t;
    }
    left = nullptr;
    right = nullptr;
}

ExprTreeNode::ExprTreeNode(string t, UnlimitedRational *v) // maybe wrong
{
    type = t;
    if (t != "VAR" && t != "VAL")
    {
        val = new UnlimitedRational();
        evaluated_value = val;
        id = "";
        left = nullptr;
        right = nullptr;
    }
    else
    {
        val = new UnlimitedRational(v->get_p(), v->get_q());
        evaluated_value = val; // temp
        id = t;
        left = nullptr;
        right = nullptr;
    }
}

ExprTreeNode::~ExprTreeNode()
{
    delete val;
    delete right;
    delete left;
    delete right;
}