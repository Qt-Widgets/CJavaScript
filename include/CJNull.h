#ifndef CJNull_H
#define CJNull_H

#include <CJObj.h>
#include <CJValue.h>

// Null Type
class CJNullType : public CJObjType {
 public:
  static CJObjTypeP instance(CJavaScript *js);

  explicit CJNullType(CJavaScript *js);

  CJValueP exec(CJavaScript *js, const std::string &name, const Values &values) override;

 private:
  static CJObjTypeP type_;
};

//------

// Null Value
class CJNull : public CJValue {
 public:
  static CJValueP value(CJavaScript *js);

 private:
  explicit CJNull(CJavaScript *js);

  CJNull(const CJNull &n);

 public:
  CJValue *dup(CJavaScript *) const override { return new CJNull(*this); }

  //---

  COptReal toReal() const override { return COptReal(0); }

  COptLong toInteger() const override { return COptLong(0); }

  bool toBoolean() const override { return false; }

  //---

  std::string toString() const override { return "null"; }

  void print(std::ostream &os) const override;
};

#endif
