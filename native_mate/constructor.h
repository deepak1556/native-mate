// This file was GENERATED by command:
//     pump.py constructor.h.pump
// DO NOT EDIT BY HAND!!!

// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE.chromium file.

#ifndef NATIVE_MATE_WRAPPABLE_CLASS_H_
#define NATIVE_MATE_WRAPPABLE_CLASS_H_

#include "base/bind.h"
#include "base/compiler_specific.h"
#include "native_mate/wrappable.h"
#include "native_mate/function_template.h"

namespace mate {

class Wrappable;

namespace internal {

// This set of templates invokes a base::Callback by converting the Arguments
// into native types. It relies on the function_template.h to provide helper
// templates.
inline Wrappable* InvokeFactory(
    Arguments* args,
    const base::Callback<Wrappable*()>& callback) {
  return callback.Run();
};

template<typename P1>
inline Wrappable* InvokeFactory(
    Arguments* args,
    const base::Callback<Wrappable*(P1)>& callback) {
  typename CallbackParamTraits<P1>::LocalType a1;
  if (!GetNextArgument(args, 0, true, &a1))
    return NULL;
  return callback.Run(a1);
};

template<typename P1, typename P2>
inline Wrappable* InvokeFactory(
    Arguments* args,
    const base::Callback<Wrappable*(P1, P2)>& callback) {
  typename CallbackParamTraits<P1>::LocalType a1;
  typename CallbackParamTraits<P2>::LocalType a2;
  if (!GetNextArgument(args, 0, true, &a1) ||
      !GetNextArgument(args, 0, false, &a2))
    return NULL;
  return callback.Run(a1, a2);
};

template<typename P1, typename P2, typename P3>
inline Wrappable* InvokeFactory(
    Arguments* args,
    const base::Callback<Wrappable*(P1, P2, P3)>& callback) {
  typename CallbackParamTraits<P1>::LocalType a1;
  typename CallbackParamTraits<P2>::LocalType a2;
  typename CallbackParamTraits<P3>::LocalType a3;
  if (!GetNextArgument(args, 0, true, &a1) ||
      !GetNextArgument(args, 0, false, &a2) ||
      !GetNextArgument(args, 0, false, &a3))
    return NULL;
  return callback.Run(a1, a2, a3);
};

template<typename P1, typename P2, typename P3, typename P4>
inline Wrappable* InvokeFactory(
    Arguments* args,
    const base::Callback<Wrappable*(P1, P2, P3, P4)>& callback) {
  typename CallbackParamTraits<P1>::LocalType a1;
  typename CallbackParamTraits<P2>::LocalType a2;
  typename CallbackParamTraits<P3>::LocalType a3;
  typename CallbackParamTraits<P4>::LocalType a4;
  if (!GetNextArgument(args, 0, true, &a1) ||
      !GetNextArgument(args, 0, false, &a2) ||
      !GetNextArgument(args, 0, false, &a3) ||
      !GetNextArgument(args, 0, false, &a4))
    return NULL;
  return callback.Run(a1, a2, a3, a4);
};

template<typename P1, typename P2, typename P3, typename P4, typename P5>
inline Wrappable* InvokeFactory(
    Arguments* args,
    const base::Callback<Wrappable*(P1, P2, P3, P4, P5)>& callback) {
  typename CallbackParamTraits<P1>::LocalType a1;
  typename CallbackParamTraits<P2>::LocalType a2;
  typename CallbackParamTraits<P3>::LocalType a3;
  typename CallbackParamTraits<P4>::LocalType a4;
  typename CallbackParamTraits<P5>::LocalType a5;
  if (!GetNextArgument(args, 0, true, &a1) ||
      !GetNextArgument(args, 0, false, &a2) ||
      !GetNextArgument(args, 0, false, &a3) ||
      !GetNextArgument(args, 0, false, &a4) ||
      !GetNextArgument(args, 0, false, &a5))
    return NULL;
  return callback.Run(a1, a2, a3, a4, a5);
};

template<typename P1, typename P2, typename P3, typename P4, typename P5,
    typename P6>
inline Wrappable* InvokeFactory(
    Arguments* args,
    const base::Callback<Wrappable*(P1, P2, P3, P4, P5, P6)>& callback) {
  typename CallbackParamTraits<P1>::LocalType a1;
  typename CallbackParamTraits<P2>::LocalType a2;
  typename CallbackParamTraits<P3>::LocalType a3;
  typename CallbackParamTraits<P4>::LocalType a4;
  typename CallbackParamTraits<P5>::LocalType a5;
  typename CallbackParamTraits<P6>::LocalType a6;
  if (!GetNextArgument(args, 0, true, &a1) ||
      !GetNextArgument(args, 0, false, &a2) ||
      !GetNextArgument(args, 0, false, &a3) ||
      !GetNextArgument(args, 0, false, &a4) ||
      !GetNextArgument(args, 0, false, &a5) ||
      !GetNextArgument(args, 0, false, &a6))
    return NULL;
  return callback.Run(a1, a2, a3, a4, a5, a6);
};

}  // namespace internal


template<typename Sig>
class Constructor {
 public:
  typedef base::Callback<Sig> WrappableFactoryFunction;

  Constructor(const base::StringPiece& name) : name_(name) {}
  virtual ~Constructor() {
    MATE_PERSISTENT_RESET(constructor_);
  }

  v8::Handle<v8::FunctionTemplate> GetFunctionTemplate(
      v8::Isolate* isolate, const WrappableFactoryFunction& factory) {
    if (constructor_.IsEmpty()) {
      v8::Local<v8::FunctionTemplate> constructor = CreateFunctionTemplate(
          isolate, base::Bind(&Constructor::New, factory));
      constructor->InstanceTemplate()->SetInternalFieldCount(1);
      constructor->SetClassName(StringToV8(isolate, name_));
      MATE_PERSISTENT_ASSIGN(v8::FunctionTemplate, isolate, constructor_,
                             constructor);
    }

    return MATE_PERSISTENT_TO_LOCAL(
        v8::FunctionTemplate, isolate, constructor_);
  }

 private:
  static MATE_METHOD_RETURN_TYPE New(const WrappableFactoryFunction& factory,
                                     v8::Isolate* isolate, Arguments* args) {
    if (!args->IsConstructCall()) {
      args->ThrowError("Requires constructor call");
      MATE_METHOD_RETURN_UNDEFINED();
    }

    Wrappable* object;
    {
      // Don't continue if the constructor throws an exception.
      v8::TryCatch try_catch;
      object = internal::InvokeFactory(args, factory);
      if (try_catch.HasCaught()) {
        try_catch.ReThrow();
        MATE_METHOD_RETURN_UNDEFINED();
      }
    }

    if (object)
      object->Wrap(isolate, args->GetThis());
    else
      args->ThrowError();

    MATE_METHOD_RETURN_UNDEFINED();
  }

  base::StringPiece name_;
  v8::UniquePersistent<v8::FunctionTemplate> constructor_;

  DISALLOW_COPY_AND_ASSIGN(Constructor);
};


template<typename T>
Wrappable* NewOperatorFactory() {
  return new T;
}

template<typename T, typename Sig>
v8::Local<v8::Function> CreateConstructor(
    v8::Isolate* isolate,
    const base::StringPiece& name,
    const base::Callback<Sig>& callback) {
  v8::Local<v8::FunctionTemplate> constructor =
      Constructor<Sig>(name).GetFunctionTemplate(isolate, callback);
  T::BuildPrototype(isolate, constructor->PrototypeTemplate());
  return constructor->GetFunction();
}

}  // namespace mate

#endif  // NATIVE_MATE_WRAPPABLE_CLASS_H_
