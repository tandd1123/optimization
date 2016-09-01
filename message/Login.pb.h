// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Login.proto

#ifndef PROTOBUF_Login_2eproto__INCLUDED
#define PROTOBUF_Login_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "Basic.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_Login_2eproto();
void protobuf_AssignDesc_Login_2eproto();
void protobuf_ShutdownFile_Login_2eproto();

class LoginRequst;
class LoginResponse;

// ===================================================================

class LoginRequst : public ::google::protobuf::Message {
 public:
  LoginRequst();
  virtual ~LoginRequst();

  LoginRequst(const LoginRequst& from);

  inline LoginRequst& operator=(const LoginRequst& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LoginRequst& default_instance();

  void Swap(LoginRequst* other);

  // implements Message ----------------------------------------------

  inline LoginRequst* New() const { return New(NULL); }

  LoginRequst* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LoginRequst& from);
  void MergeFrom(const LoginRequst& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(LoginRequst* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .CommonRequest head = 1;
  bool has_head() const;
  void clear_head();
  static const int kHeadFieldNumber = 1;
  const ::CommonRequest& head() const;
  ::CommonRequest* mutable_head();
  ::CommonRequest* release_head();
  void set_allocated_head(::CommonRequest* head);

  // optional string accountid = 2;
  void clear_accountid();
  static const int kAccountidFieldNumber = 2;
  const ::std::string& accountid() const;
  void set_accountid(const ::std::string& value);
  void set_accountid(const char* value);
  void set_accountid(const char* value, size_t size);
  ::std::string* mutable_accountid();
  ::std::string* release_accountid();
  void set_allocated_accountid(::std::string* accountid);

  // optional string username = 3;
  void clear_username();
  static const int kUsernameFieldNumber = 3;
  const ::std::string& username() const;
  void set_username(const ::std::string& value);
  void set_username(const char* value);
  void set_username(const char* value, size_t size);
  ::std::string* mutable_username();
  ::std::string* release_username();
  void set_allocated_username(::std::string* username);

  // optional string userpwd = 4;
  void clear_userpwd();
  static const int kUserpwdFieldNumber = 4;
  const ::std::string& userpwd() const;
  void set_userpwd(const ::std::string& value);
  void set_userpwd(const char* value);
  void set_userpwd(const char* value, size_t size);
  ::std::string* mutable_userpwd();
  ::std::string* release_userpwd();
  void set_allocated_userpwd(::std::string* userpwd);

  // optional .UserSex sex = 5;
  void clear_sex();
  static const int kSexFieldNumber = 5;
  ::UserSex sex() const;
  void set_sex(::UserSex value);

  // optional string headurl = 6;
  void clear_headurl();
  static const int kHeadurlFieldNumber = 6;
  const ::std::string& headurl() const;
  void set_headurl(const ::std::string& value);
  void set_headurl(const char* value);
  void set_headurl(const char* value, size_t size);
  ::std::string* mutable_headurl();
  ::std::string* release_headurl();
  void set_allocated_headurl(::std::string* headurl);

  // optional string email = 7;
  void clear_email();
  static const int kEmailFieldNumber = 7;
  const ::std::string& email() const;
  void set_email(const ::std::string& value);
  void set_email(const char* value);
  void set_email(const char* value, size_t size);
  ::std::string* mutable_email();
  ::std::string* release_email();
  void set_allocated_email(::std::string* email);

  // optional bytes userType = 8;
  void clear_usertype();
  static const int kUserTypeFieldNumber = 8;
  const ::std::string& usertype() const;
  void set_usertype(const ::std::string& value);
  void set_usertype(const char* value);
  void set_usertype(const void* value, size_t size);
  ::std::string* mutable_usertype();
  ::std::string* release_usertype();
  void set_allocated_usertype(::std::string* usertype);

  // optional uint32 channel = 9;
  void clear_channel();
  static const int kChannelFieldNumber = 9;
  ::google::protobuf::uint32 channel() const;
  void set_channel(::google::protobuf::uint32 value);

  // optional uint32 languige = 10;
  void clear_languige();
  static const int kLanguigeFieldNumber = 10;
  ::google::protobuf::uint32 languige() const;
  void set_languige(::google::protobuf::uint32 value);

  // optional string version = 11;
  void clear_version();
  static const int kVersionFieldNumber = 11;
  const ::std::string& version() const;
  void set_version(const ::std::string& value);
  void set_version(const char* value);
  void set_version(const char* value, size_t size);
  ::std::string* mutable_version();
  ::std::string* release_version();
  void set_allocated_version(::std::string* version);

  // @@protoc_insertion_point(class_scope:LoginRequst)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::CommonRequest* head_;
  ::google::protobuf::internal::ArenaStringPtr accountid_;
  ::google::protobuf::internal::ArenaStringPtr username_;
  ::google::protobuf::internal::ArenaStringPtr userpwd_;
  ::google::protobuf::internal::ArenaStringPtr headurl_;
  ::google::protobuf::internal::ArenaStringPtr email_;
  int sex_;
  ::google::protobuf::uint32 channel_;
  ::google::protobuf::internal::ArenaStringPtr usertype_;
  ::google::protobuf::internal::ArenaStringPtr version_;
  ::google::protobuf::uint32 languige_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Login_2eproto();
  friend void protobuf_AssignDesc_Login_2eproto();
  friend void protobuf_ShutdownFile_Login_2eproto();

  void InitAsDefaultInstance();
  static LoginRequst* default_instance_;
};
// -------------------------------------------------------------------

class LoginResponse : public ::google::protobuf::Message {
 public:
  LoginResponse();
  virtual ~LoginResponse();

  LoginResponse(const LoginResponse& from);

  inline LoginResponse& operator=(const LoginResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LoginResponse& default_instance();

  void Swap(LoginResponse* other);

  // implements Message ----------------------------------------------

  inline LoginResponse* New() const { return New(NULL); }

  LoginResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LoginResponse& from);
  void MergeFrom(const LoginResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(LoginResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .ResponseHeader head = 1;
  bool has_head() const;
  void clear_head();
  static const int kHeadFieldNumber = 1;
  const ::ResponseHeader& head() const;
  ::ResponseHeader* mutable_head();
  ::ResponseHeader* release_head();
  void set_allocated_head(::ResponseHeader* head);

  // optional bool isRegister = 2;
  void clear_isregister();
  static const int kIsRegisterFieldNumber = 2;
  bool isregister() const;
  void set_isregister(bool value);

  // @@protoc_insertion_point(class_scope:LoginResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::ResponseHeader* head_;
  bool isregister_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_Login_2eproto();
  friend void protobuf_AssignDesc_Login_2eproto();
  friend void protobuf_ShutdownFile_Login_2eproto();

  void InitAsDefaultInstance();
  static LoginResponse* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// LoginRequst

// optional .CommonRequest head = 1;
inline bool LoginRequst::has_head() const {
  return !_is_default_instance_ && head_ != NULL;
}
inline void LoginRequst::clear_head() {
  if (GetArenaNoVirtual() == NULL && head_ != NULL) delete head_;
  head_ = NULL;
}
inline const ::CommonRequest& LoginRequst::head() const {
  // @@protoc_insertion_point(field_get:LoginRequst.head)
  return head_ != NULL ? *head_ : *default_instance_->head_;
}
inline ::CommonRequest* LoginRequst::mutable_head() {
  
  if (head_ == NULL) {
    head_ = new ::CommonRequest;
  }
  // @@protoc_insertion_point(field_mutable:LoginRequst.head)
  return head_;
}
inline ::CommonRequest* LoginRequst::release_head() {
  // @@protoc_insertion_point(field_release:LoginRequst.head)
  
  ::CommonRequest* temp = head_;
  head_ = NULL;
  return temp;
}
inline void LoginRequst::set_allocated_head(::CommonRequest* head) {
  delete head_;
  head_ = head;
  if (head) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:LoginRequst.head)
}

// optional string accountid = 2;
inline void LoginRequst::clear_accountid() {
  accountid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& LoginRequst::accountid() const {
  // @@protoc_insertion_point(field_get:LoginRequst.accountid)
  return accountid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_accountid(const ::std::string& value) {
  
  accountid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:LoginRequst.accountid)
}
inline void LoginRequst::set_accountid(const char* value) {
  
  accountid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:LoginRequst.accountid)
}
inline void LoginRequst::set_accountid(const char* value, size_t size) {
  
  accountid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:LoginRequst.accountid)
}
inline ::std::string* LoginRequst::mutable_accountid() {
  
  // @@protoc_insertion_point(field_mutable:LoginRequst.accountid)
  return accountid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* LoginRequst::release_accountid() {
  // @@protoc_insertion_point(field_release:LoginRequst.accountid)
  
  return accountid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_allocated_accountid(::std::string* accountid) {
  if (accountid != NULL) {
    
  } else {
    
  }
  accountid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), accountid);
  // @@protoc_insertion_point(field_set_allocated:LoginRequst.accountid)
}

// optional string username = 3;
inline void LoginRequst::clear_username() {
  username_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& LoginRequst::username() const {
  // @@protoc_insertion_point(field_get:LoginRequst.username)
  return username_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_username(const ::std::string& value) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:LoginRequst.username)
}
inline void LoginRequst::set_username(const char* value) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:LoginRequst.username)
}
inline void LoginRequst::set_username(const char* value, size_t size) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:LoginRequst.username)
}
inline ::std::string* LoginRequst::mutable_username() {
  
  // @@protoc_insertion_point(field_mutable:LoginRequst.username)
  return username_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* LoginRequst::release_username() {
  // @@protoc_insertion_point(field_release:LoginRequst.username)
  
  return username_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_allocated_username(::std::string* username) {
  if (username != NULL) {
    
  } else {
    
  }
  username_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), username);
  // @@protoc_insertion_point(field_set_allocated:LoginRequst.username)
}

// optional string userpwd = 4;
inline void LoginRequst::clear_userpwd() {
  userpwd_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& LoginRequst::userpwd() const {
  // @@protoc_insertion_point(field_get:LoginRequst.userpwd)
  return userpwd_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_userpwd(const ::std::string& value) {
  
  userpwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:LoginRequst.userpwd)
}
inline void LoginRequst::set_userpwd(const char* value) {
  
  userpwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:LoginRequst.userpwd)
}
inline void LoginRequst::set_userpwd(const char* value, size_t size) {
  
  userpwd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:LoginRequst.userpwd)
}
inline ::std::string* LoginRequst::mutable_userpwd() {
  
  // @@protoc_insertion_point(field_mutable:LoginRequst.userpwd)
  return userpwd_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* LoginRequst::release_userpwd() {
  // @@protoc_insertion_point(field_release:LoginRequst.userpwd)
  
  return userpwd_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_allocated_userpwd(::std::string* userpwd) {
  if (userpwd != NULL) {
    
  } else {
    
  }
  userpwd_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), userpwd);
  // @@protoc_insertion_point(field_set_allocated:LoginRequst.userpwd)
}

// optional .UserSex sex = 5;
inline void LoginRequst::clear_sex() {
  sex_ = 0;
}
inline ::UserSex LoginRequst::sex() const {
  // @@protoc_insertion_point(field_get:LoginRequst.sex)
  return static_cast< ::UserSex >(sex_);
}
inline void LoginRequst::set_sex(::UserSex value) {
  
  sex_ = value;
  // @@protoc_insertion_point(field_set:LoginRequst.sex)
}

// optional string headurl = 6;
inline void LoginRequst::clear_headurl() {
  headurl_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& LoginRequst::headurl() const {
  // @@protoc_insertion_point(field_get:LoginRequst.headurl)
  return headurl_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_headurl(const ::std::string& value) {
  
  headurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:LoginRequst.headurl)
}
inline void LoginRequst::set_headurl(const char* value) {
  
  headurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:LoginRequst.headurl)
}
inline void LoginRequst::set_headurl(const char* value, size_t size) {
  
  headurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:LoginRequst.headurl)
}
inline ::std::string* LoginRequst::mutable_headurl() {
  
  // @@protoc_insertion_point(field_mutable:LoginRequst.headurl)
  return headurl_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* LoginRequst::release_headurl() {
  // @@protoc_insertion_point(field_release:LoginRequst.headurl)
  
  return headurl_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_allocated_headurl(::std::string* headurl) {
  if (headurl != NULL) {
    
  } else {
    
  }
  headurl_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), headurl);
  // @@protoc_insertion_point(field_set_allocated:LoginRequst.headurl)
}

// optional string email = 7;
inline void LoginRequst::clear_email() {
  email_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& LoginRequst::email() const {
  // @@protoc_insertion_point(field_get:LoginRequst.email)
  return email_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_email(const ::std::string& value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:LoginRequst.email)
}
inline void LoginRequst::set_email(const char* value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:LoginRequst.email)
}
inline void LoginRequst::set_email(const char* value, size_t size) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:LoginRequst.email)
}
inline ::std::string* LoginRequst::mutable_email() {
  
  // @@protoc_insertion_point(field_mutable:LoginRequst.email)
  return email_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* LoginRequst::release_email() {
  // @@protoc_insertion_point(field_release:LoginRequst.email)
  
  return email_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_allocated_email(::std::string* email) {
  if (email != NULL) {
    
  } else {
    
  }
  email_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), email);
  // @@protoc_insertion_point(field_set_allocated:LoginRequst.email)
}

// optional bytes userType = 8;
inline void LoginRequst::clear_usertype() {
  usertype_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& LoginRequst::usertype() const {
  // @@protoc_insertion_point(field_get:LoginRequst.userType)
  return usertype_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_usertype(const ::std::string& value) {
  
  usertype_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:LoginRequst.userType)
}
inline void LoginRequst::set_usertype(const char* value) {
  
  usertype_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:LoginRequst.userType)
}
inline void LoginRequst::set_usertype(const void* value, size_t size) {
  
  usertype_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:LoginRequst.userType)
}
inline ::std::string* LoginRequst::mutable_usertype() {
  
  // @@protoc_insertion_point(field_mutable:LoginRequst.userType)
  return usertype_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* LoginRequst::release_usertype() {
  // @@protoc_insertion_point(field_release:LoginRequst.userType)
  
  return usertype_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_allocated_usertype(::std::string* usertype) {
  if (usertype != NULL) {
    
  } else {
    
  }
  usertype_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), usertype);
  // @@protoc_insertion_point(field_set_allocated:LoginRequst.userType)
}

// optional uint32 channel = 9;
inline void LoginRequst::clear_channel() {
  channel_ = 0u;
}
inline ::google::protobuf::uint32 LoginRequst::channel() const {
  // @@protoc_insertion_point(field_get:LoginRequst.channel)
  return channel_;
}
inline void LoginRequst::set_channel(::google::protobuf::uint32 value) {
  
  channel_ = value;
  // @@protoc_insertion_point(field_set:LoginRequst.channel)
}

// optional uint32 languige = 10;
inline void LoginRequst::clear_languige() {
  languige_ = 0u;
}
inline ::google::protobuf::uint32 LoginRequst::languige() const {
  // @@protoc_insertion_point(field_get:LoginRequst.languige)
  return languige_;
}
inline void LoginRequst::set_languige(::google::protobuf::uint32 value) {
  
  languige_ = value;
  // @@protoc_insertion_point(field_set:LoginRequst.languige)
}

// optional string version = 11;
inline void LoginRequst::clear_version() {
  version_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& LoginRequst::version() const {
  // @@protoc_insertion_point(field_get:LoginRequst.version)
  return version_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_version(const ::std::string& value) {
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:LoginRequst.version)
}
inline void LoginRequst::set_version(const char* value) {
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:LoginRequst.version)
}
inline void LoginRequst::set_version(const char* value, size_t size) {
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:LoginRequst.version)
}
inline ::std::string* LoginRequst::mutable_version() {
  
  // @@protoc_insertion_point(field_mutable:LoginRequst.version)
  return version_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* LoginRequst::release_version() {
  // @@protoc_insertion_point(field_release:LoginRequst.version)
  
  return version_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void LoginRequst::set_allocated_version(::std::string* version) {
  if (version != NULL) {
    
  } else {
    
  }
  version_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), version);
  // @@protoc_insertion_point(field_set_allocated:LoginRequst.version)
}

// -------------------------------------------------------------------

// LoginResponse

// optional .ResponseHeader head = 1;
inline bool LoginResponse::has_head() const {
  return !_is_default_instance_ && head_ != NULL;
}
inline void LoginResponse::clear_head() {
  if (GetArenaNoVirtual() == NULL && head_ != NULL) delete head_;
  head_ = NULL;
}
inline const ::ResponseHeader& LoginResponse::head() const {
  // @@protoc_insertion_point(field_get:LoginResponse.head)
  return head_ != NULL ? *head_ : *default_instance_->head_;
}
inline ::ResponseHeader* LoginResponse::mutable_head() {
  
  if (head_ == NULL) {
    head_ = new ::ResponseHeader;
  }
  // @@protoc_insertion_point(field_mutable:LoginResponse.head)
  return head_;
}
inline ::ResponseHeader* LoginResponse::release_head() {
  // @@protoc_insertion_point(field_release:LoginResponse.head)
  
  ::ResponseHeader* temp = head_;
  head_ = NULL;
  return temp;
}
inline void LoginResponse::set_allocated_head(::ResponseHeader* head) {
  delete head_;
  head_ = head;
  if (head) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:LoginResponse.head)
}

// optional bool isRegister = 2;
inline void LoginResponse::clear_isregister() {
  isregister_ = false;
}
inline bool LoginResponse::isregister() const {
  // @@protoc_insertion_point(field_get:LoginResponse.isRegister)
  return isregister_;
}
inline void LoginResponse::set_isregister(bool value) {
  
  isregister_ = value;
  // @@protoc_insertion_point(field_set:LoginResponse.isRegister)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Login_2eproto__INCLUDED