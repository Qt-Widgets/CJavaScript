#ifndef CJConsole_H
#define CJConsole_H

#include <CJObj.h>

// Console Type
class CJConsoleType : public CJObjType {
 public:
  static CJObjTypeP instance(CJavaScript *js);

  CJConsoleType(CJavaScript *js);

  CJValueP exec(CJavaScript *js, const std::string &name, const Values &values) override;

 private:
  static CJObjTypeP type_;
};

//------

// Console Object
class CJConsoleObject : public CJObj {
 public:
  CJConsoleObject(CJavaScript *js);

  CJConsoleObject(const CJConsoleObject &obj);

  CJValue *dup(CJavaScript *) const override { return new CJConsoleObject(*this); }

  CJValueP execNameFn(CJavaScript *js, const std::string &name, const Values &values) override;
};

#endif
