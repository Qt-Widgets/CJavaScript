#include <CJExecReturn.h>
#include <CJExecExpression.h>
#include <CJavaScript.h>

CJExecReturn::
CJExecReturn() :
 CJToken(CJToken::Type::ExecReturn)
{
}

CJValueP
CJExecReturn::
exec(CJavaScript *js)
{
  CJValueP value;

  if (expr_)
    value = expr_->exec(js);

  CJExecBlockP block = js->getCurrentBlock();

  if (block) {
    if (value && value->type() == CJToken::Type::Function) {
      CJFunction *fn = dynamic_cast<CJFunction *>(value->dup(js));

      fn->makeUnique(js);

      value = CJValueP(fn);
    }

    block->setRetVal(value);

    block->setReturnFlag(true);
  }

  return value;
}

std::string
CJExecReturn::
toString() const
{
  std::ostringstream ss; ss << *this;

  return ss.str();
}

void
CJExecReturn::
print(std::ostream &os) const
{
  if (expr_)
    os << "return " << *expr_;
}
