#ifndef CJFunction_H
#define CJFunction_H

#include <CJFunctionBase.h>

// User Function Type
class CJFunctionType : public CJObjType {
 public:
  static CJObjTypeP instance(CJavaScript *js);

  CJFunctionType(CJavaScript *js);

  CJValueP getProperty(CJavaScript *js, const std::string &key) const override;

  CJValueP execType(CJavaScript *js, const std::string &name, const Values &values) override;

  CJValueP exec(CJavaScript *js, const std::string &name, const Values &values) override;

 private:
  static CJObjTypeP type_;
};

//------

// User Function
class CJFunction : public CJFunctionBase {
 public:
  typedef std::vector<std::string> Args;

 public:
  CJFunction(CJavaScript *js, const std::string &name="",
             const Args &args=Args(), CJExecBlockP block=CJExecBlockP());

  CJValue *dup(CJavaScript *js) const override {
    return new CJFunction(js, name_, args_, block_);
  }

  void init(CJFunctionP fn);

  bool isUserFunction() const override { return true; }

  bool hasObjectValue() const override { return true; }

  void setScope(CJavaScript *js, CJDictionaryP parentScope=CJDictionaryP());

  const Args &args() const { return args_; }
  void setArgs(const Args &v) { args_ = v; }

  const CJExecBlockP &block() const { return block_; }
  void setBlock(const CJExecBlockP &v) { block_ = v; }

  const CJDictionaryP &scope() const { return scope_; }
  void setScope(const CJDictionaryP &v) { scope_ = v; }

  CJValueP getScopeProperty(const std::string &name) const;
  void setScopeProperty(const std::string &name, CJValueP value);

  CJValueP exec(CJavaScript *js, const Values &values) override;

  std::string toString() const override;

  void print(std::ostream &os) const override;

  friend std::ostream &operator<<(std::ostream &os, const CJFunction &rhs) {
    rhs.print(os);

    return os;
  }

 private:
  Args          args_;
  CJExecBlockP  block_;
  CJDictionaryP scope_;
};

#endif
