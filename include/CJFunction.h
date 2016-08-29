#ifndef CJFunction_H
#define CJFunction_H

#include <CJObj.h>
#include <CJDictionary.h>
#include <vector>

// Function Type
class CJFunctionType : public CJObjType {
 public:
  static CJObjTypeP instance(CJavaScript *js, const std::string &name);

  CJFunctionType(CJavaScript *js, const std::string &name);

  const std::string &name() const { return name_; }

  CJValueP exec(CJavaScript *js, const std::string &name, const Values &values) override;

 private:
  typedef std::map<std::string,CJObjTypeP> NameTypeMap;

  static NameTypeMap nameTypeMap_;

  std::string name_;
};

//------

// Function Value
class CJFunction : public CJObj {
 public:
  enum class Type {
    Normal,
    Real,
    Real2,
    Random,
    Type,
    ObjectType,
    Object,
    User,
    Global
  };

  typedef std::vector<CJValueP> Values;

 public:
  CJFunction(CJavaScript *js, const std::string &name, Type type=Type::Normal);

  CJValue *dup(CJavaScript *) const override { assert(false); return 0; }

  bool isProtoValue() const override { return true; }

  const std::string &name() const { return name_; }

  std::string toString() const override { return name_; }

  virtual bool hasObjectValue() const { return false; }

  const Type &type() const { return type_; }

  virtual CJValueP exec(CJavaScript *js, const Values &values) = 0;

  void print(std::ostream &os) const override {
    os << name_ << "()";
  }

 protected:
  std::string name_;
  Type        type_;
};

#endif