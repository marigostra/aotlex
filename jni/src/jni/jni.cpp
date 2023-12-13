
#include<stdio.h>
#include<string>
#include<memory>
#include<iostream>

#include"jni.h"
#include"aot_Aot.h"

#include "../aot/LemmatizerLib/MorphologyHolder.h"
#include"../aot/LemmatizerLib/Lemmatizers.h"
#include"../aot/LemmatizerLib/Morphan.h"

JNIEXPORT void JNICALL Java_aot_Aot_initImpl
(JNIEnv* env, jobject obj)
{
  std::auto_ptr<CMorphologyHolder> h(new CMorphologyHolder());
  if (!h->LoadLemmatizer(morphRussian))
    std::cerr << "Cannot load morphology\n";
  const CMorphologyHolder* ptr = h.get();
  const jbyteArray ar = env->NewByteArray(sizeof(CMorphologyHolder*));
  env->SetByteArrayRegion (ar, 0, sizeof(CMorphologyHolder*), (jbyte*)&ptr);
  const jclass cl = env->GetObjectClass(obj);
  const jfieldID id = env->GetFieldID(cl, "core", "[B");
  env->SetObjectField(obj, id, ar);
  h.release();
}

JNIEXPORT jbyteArray JNICALL Java_aot_Aot_lemmatizeImpl
(JNIEnv* env, jobject obj, jbyteArray word)
{
  const jclass cl = env->GetObjectClass(obj);
  const jfieldID id = env->GetFieldID(cl, "core", "[B");
  const jbyteArray ar = (jbyteArray)env->GetObjectField(obj, id);
  const CMorphologyHolder* h = NULL;
  env->GetByteArrayRegion (ar, 0, sizeof(CMorphologyHolder*), (jbyte*)&h);
  const jsize len = env->GetArrayLength(word);
  const jbyte* bytes = env->GetByteArrayElements(word, NULL); 
  std::string w;
  w.reserve(len);
  for(jsize i = 0;i < len;i++)
    w += bytes[i];
  const std::string s = convert_from_utf8(w.c_str(), morphRussian);
  const std::string res = LemmatizeJson(s.c_str(), h, /*printForms*/true, true, true);
  const jbyteArray ret = env->NewByteArray(res.length());
  env->SetByteArrayRegion (ret, 0, res.length(), (jbyte*)res.c_str());
  return ret;
}
