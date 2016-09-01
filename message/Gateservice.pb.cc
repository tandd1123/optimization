// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Gateservice.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Gateservice.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* PBClientMsg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PBClientMsg_reflection_ = NULL;
const ::google::protobuf::Descriptor* PBServerMsg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PBServerMsg_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Gateservice_2eproto() {
  protobuf_AddDesc_Gateservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Gateservice.proto");
  GOOGLE_CHECK(file != NULL);
  PBClientMsg_descriptor_ = file->message_type(0);
  static const int PBClientMsg_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PBClientMsg, accountid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PBClientMsg, proxy_),
  };
  PBClientMsg_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      PBClientMsg_descriptor_,
      PBClientMsg::default_instance_,
      PBClientMsg_offsets_,
      -1,
      -1,
      -1,
      sizeof(PBClientMsg),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PBClientMsg, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PBClientMsg, _is_default_instance_));
  PBServerMsg_descriptor_ = file->message_type(1);
  static const int PBServerMsg_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PBServerMsg, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PBServerMsg, proxy_),
  };
  PBServerMsg_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      PBServerMsg_descriptor_,
      PBServerMsg::default_instance_,
      PBServerMsg_offsets_,
      -1,
      -1,
      -1,
      sizeof(PBServerMsg),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PBServerMsg, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PBServerMsg, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Gateservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      PBClientMsg_descriptor_, &PBClientMsg::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      PBServerMsg_descriptor_, &PBServerMsg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Gateservice_2eproto() {
  delete PBClientMsg::default_instance_;
  delete PBClientMsg_reflection_;
  delete PBServerMsg::default_instance_;
  delete PBServerMsg_reflection_;
}

void protobuf_AddDesc_Gateservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021Gateservice.proto\"/\n\013PBClientMsg\022\021\n\tac"
    "countid\030\001 \001(\t\022\r\n\005proxy\030\002 \001(\t\")\n\013PBServer"
    "Msg\022\013\n\003key\030\001 \001(\t\022\r\n\005proxy\030\002 \001(\tb\006proto3", 119);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Gateservice.proto", &protobuf_RegisterTypes);
  PBClientMsg::default_instance_ = new PBClientMsg();
  PBServerMsg::default_instance_ = new PBServerMsg();
  PBClientMsg::default_instance_->InitAsDefaultInstance();
  PBServerMsg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Gateservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Gateservice_2eproto {
  StaticDescriptorInitializer_Gateservice_2eproto() {
    protobuf_AddDesc_Gateservice_2eproto();
  }
} static_descriptor_initializer_Gateservice_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PBClientMsg::kAccountidFieldNumber;
const int PBClientMsg::kProxyFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PBClientMsg::PBClientMsg()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:PBClientMsg)
}

void PBClientMsg::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

PBClientMsg::PBClientMsg(const PBClientMsg& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:PBClientMsg)
}

void PBClientMsg::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  accountid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  proxy_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

PBClientMsg::~PBClientMsg() {
  // @@protoc_insertion_point(destructor:PBClientMsg)
  SharedDtor();
}

void PBClientMsg::SharedDtor() {
  accountid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  proxy_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void PBClientMsg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PBClientMsg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PBClientMsg_descriptor_;
}

const PBClientMsg& PBClientMsg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Gateservice_2eproto();
  return *default_instance_;
}

PBClientMsg* PBClientMsg::default_instance_ = NULL;

PBClientMsg* PBClientMsg::New(::google::protobuf::Arena* arena) const {
  PBClientMsg* n = new PBClientMsg;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PBClientMsg::Clear() {
// @@protoc_insertion_point(message_clear_start:PBClientMsg)
  accountid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  proxy_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool PBClientMsg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PBClientMsg)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string accountid = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_accountid()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->accountid().data(), this->accountid().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "PBClientMsg.accountid"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_proxy;
        break;
      }

      // optional string proxy = 2;
      case 2: {
        if (tag == 18) {
         parse_proxy:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_proxy()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->proxy().data(), this->proxy().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "PBClientMsg.proxy"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:PBClientMsg)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PBClientMsg)
  return false;
#undef DO_
}

void PBClientMsg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PBClientMsg)
  // optional string accountid = 1;
  if (this->accountid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->accountid().data(), this->accountid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "PBClientMsg.accountid");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->accountid(), output);
  }

  // optional string proxy = 2;
  if (this->proxy().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->proxy().data(), this->proxy().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "PBClientMsg.proxy");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->proxy(), output);
  }

  // @@protoc_insertion_point(serialize_end:PBClientMsg)
}

::google::protobuf::uint8* PBClientMsg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:PBClientMsg)
  // optional string accountid = 1;
  if (this->accountid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->accountid().data(), this->accountid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "PBClientMsg.accountid");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->accountid(), target);
  }

  // optional string proxy = 2;
  if (this->proxy().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->proxy().data(), this->proxy().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "PBClientMsg.proxy");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->proxy(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:PBClientMsg)
  return target;
}

int PBClientMsg::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:PBClientMsg)
  int total_size = 0;

  // optional string accountid = 1;
  if (this->accountid().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->accountid());
  }

  // optional string proxy = 2;
  if (this->proxy().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->proxy());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PBClientMsg::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:PBClientMsg)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const PBClientMsg* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const PBClientMsg>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:PBClientMsg)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:PBClientMsg)
    MergeFrom(*source);
  }
}

void PBClientMsg::MergeFrom(const PBClientMsg& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:PBClientMsg)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.accountid().size() > 0) {

    accountid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.accountid_);
  }
  if (from.proxy().size() > 0) {

    proxy_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.proxy_);
  }
}

void PBClientMsg::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:PBClientMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PBClientMsg::CopyFrom(const PBClientMsg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:PBClientMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PBClientMsg::IsInitialized() const {

  return true;
}

void PBClientMsg::Swap(PBClientMsg* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PBClientMsg::InternalSwap(PBClientMsg* other) {
  accountid_.Swap(&other->accountid_);
  proxy_.Swap(&other->proxy_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PBClientMsg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PBClientMsg_descriptor_;
  metadata.reflection = PBClientMsg_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// PBClientMsg

// optional string accountid = 1;
void PBClientMsg::clear_accountid() {
  accountid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& PBClientMsg::accountid() const {
  // @@protoc_insertion_point(field_get:PBClientMsg.accountid)
  return accountid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void PBClientMsg::set_accountid(const ::std::string& value) {
  
  accountid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PBClientMsg.accountid)
}
 void PBClientMsg::set_accountid(const char* value) {
  
  accountid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PBClientMsg.accountid)
}
 void PBClientMsg::set_accountid(const char* value, size_t size) {
  
  accountid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PBClientMsg.accountid)
}
 ::std::string* PBClientMsg::mutable_accountid() {
  
  // @@protoc_insertion_point(field_mutable:PBClientMsg.accountid)
  return accountid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* PBClientMsg::release_accountid() {
  // @@protoc_insertion_point(field_release:PBClientMsg.accountid)
  
  return accountid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void PBClientMsg::set_allocated_accountid(::std::string* accountid) {
  if (accountid != NULL) {
    
  } else {
    
  }
  accountid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), accountid);
  // @@protoc_insertion_point(field_set_allocated:PBClientMsg.accountid)
}

// optional string proxy = 2;
void PBClientMsg::clear_proxy() {
  proxy_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& PBClientMsg::proxy() const {
  // @@protoc_insertion_point(field_get:PBClientMsg.proxy)
  return proxy_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void PBClientMsg::set_proxy(const ::std::string& value) {
  
  proxy_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PBClientMsg.proxy)
}
 void PBClientMsg::set_proxy(const char* value) {
  
  proxy_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PBClientMsg.proxy)
}
 void PBClientMsg::set_proxy(const char* value, size_t size) {
  
  proxy_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PBClientMsg.proxy)
}
 ::std::string* PBClientMsg::mutable_proxy() {
  
  // @@protoc_insertion_point(field_mutable:PBClientMsg.proxy)
  return proxy_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* PBClientMsg::release_proxy() {
  // @@protoc_insertion_point(field_release:PBClientMsg.proxy)
  
  return proxy_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void PBClientMsg::set_allocated_proxy(::std::string* proxy) {
  if (proxy != NULL) {
    
  } else {
    
  }
  proxy_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), proxy);
  // @@protoc_insertion_point(field_set_allocated:PBClientMsg.proxy)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int PBServerMsg::kKeyFieldNumber;
const int PBServerMsg::kProxyFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

PBServerMsg::PBServerMsg()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:PBServerMsg)
}

void PBServerMsg::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

PBServerMsg::PBServerMsg(const PBServerMsg& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:PBServerMsg)
}

void PBServerMsg::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  key_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  proxy_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

PBServerMsg::~PBServerMsg() {
  // @@protoc_insertion_point(destructor:PBServerMsg)
  SharedDtor();
}

void PBServerMsg::SharedDtor() {
  key_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  proxy_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void PBServerMsg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PBServerMsg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PBServerMsg_descriptor_;
}

const PBServerMsg& PBServerMsg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Gateservice_2eproto();
  return *default_instance_;
}

PBServerMsg* PBServerMsg::default_instance_ = NULL;

PBServerMsg* PBServerMsg::New(::google::protobuf::Arena* arena) const {
  PBServerMsg* n = new PBServerMsg;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PBServerMsg::Clear() {
// @@protoc_insertion_point(message_clear_start:PBServerMsg)
  key_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  proxy_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool PBServerMsg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PBServerMsg)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string key = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_key()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->key().data(), this->key().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "PBServerMsg.key"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_proxy;
        break;
      }

      // optional string proxy = 2;
      case 2: {
        if (tag == 18) {
         parse_proxy:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_proxy()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->proxy().data(), this->proxy().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "PBServerMsg.proxy"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:PBServerMsg)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PBServerMsg)
  return false;
#undef DO_
}

void PBServerMsg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PBServerMsg)
  // optional string key = 1;
  if (this->key().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->key().data(), this->key().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "PBServerMsg.key");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->key(), output);
  }

  // optional string proxy = 2;
  if (this->proxy().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->proxy().data(), this->proxy().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "PBServerMsg.proxy");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->proxy(), output);
  }

  // @@protoc_insertion_point(serialize_end:PBServerMsg)
}

::google::protobuf::uint8* PBServerMsg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:PBServerMsg)
  // optional string key = 1;
  if (this->key().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->key().data(), this->key().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "PBServerMsg.key");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->key(), target);
  }

  // optional string proxy = 2;
  if (this->proxy().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->proxy().data(), this->proxy().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "PBServerMsg.proxy");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->proxy(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:PBServerMsg)
  return target;
}

int PBServerMsg::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:PBServerMsg)
  int total_size = 0;

  // optional string key = 1;
  if (this->key().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->key());
  }

  // optional string proxy = 2;
  if (this->proxy().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->proxy());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PBServerMsg::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:PBServerMsg)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const PBServerMsg* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const PBServerMsg>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:PBServerMsg)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:PBServerMsg)
    MergeFrom(*source);
  }
}

void PBServerMsg::MergeFrom(const PBServerMsg& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:PBServerMsg)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.key().size() > 0) {

    key_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.key_);
  }
  if (from.proxy().size() > 0) {

    proxy_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.proxy_);
  }
}

void PBServerMsg::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:PBServerMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PBServerMsg::CopyFrom(const PBServerMsg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:PBServerMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PBServerMsg::IsInitialized() const {

  return true;
}

void PBServerMsg::Swap(PBServerMsg* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PBServerMsg::InternalSwap(PBServerMsg* other) {
  key_.Swap(&other->key_);
  proxy_.Swap(&other->proxy_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PBServerMsg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PBServerMsg_descriptor_;
  metadata.reflection = PBServerMsg_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// PBServerMsg

// optional string key = 1;
void PBServerMsg::clear_key() {
  key_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& PBServerMsg::key() const {
  // @@protoc_insertion_point(field_get:PBServerMsg.key)
  return key_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void PBServerMsg::set_key(const ::std::string& value) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PBServerMsg.key)
}
 void PBServerMsg::set_key(const char* value) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PBServerMsg.key)
}
 void PBServerMsg::set_key(const char* value, size_t size) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PBServerMsg.key)
}
 ::std::string* PBServerMsg::mutable_key() {
  
  // @@protoc_insertion_point(field_mutable:PBServerMsg.key)
  return key_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* PBServerMsg::release_key() {
  // @@protoc_insertion_point(field_release:PBServerMsg.key)
  
  return key_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void PBServerMsg::set_allocated_key(::std::string* key) {
  if (key != NULL) {
    
  } else {
    
  }
  key_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), key);
  // @@protoc_insertion_point(field_set_allocated:PBServerMsg.key)
}

// optional string proxy = 2;
void PBServerMsg::clear_proxy() {
  proxy_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& PBServerMsg::proxy() const {
  // @@protoc_insertion_point(field_get:PBServerMsg.proxy)
  return proxy_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void PBServerMsg::set_proxy(const ::std::string& value) {
  
  proxy_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PBServerMsg.proxy)
}
 void PBServerMsg::set_proxy(const char* value) {
  
  proxy_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PBServerMsg.proxy)
}
 void PBServerMsg::set_proxy(const char* value, size_t size) {
  
  proxy_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PBServerMsg.proxy)
}
 ::std::string* PBServerMsg::mutable_proxy() {
  
  // @@protoc_insertion_point(field_mutable:PBServerMsg.proxy)
  return proxy_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* PBServerMsg::release_proxy() {
  // @@protoc_insertion_point(field_release:PBServerMsg.proxy)
  
  return proxy_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void PBServerMsg::set_allocated_proxy(::std::string* proxy) {
  if (proxy != NULL) {
    
  } else {
    
  }
  proxy_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), proxy);
  // @@protoc_insertion_point(field_set_allocated:PBServerMsg.proxy)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
