// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cs_game.proto

#ifndef PROTOBUF_cs_5fgame_2eproto__INCLUDED
#define PROTOBUF_cs_5fgame_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace cs {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_cs_5fgame_2eproto();
void protobuf_AssignDesc_cs_5fgame_2eproto();
void protobuf_ShutdownFile_cs_5fgame_2eproto();

class CSGetGameSvrMinLoadReq;
class CSGetGameSvrMinLoadRes;
class CSGetGameSvrMinLoadRes_GameSvrHost;
class CSHeartbeatReq;
class CSHeartbeatRes;
class CSUpdateSecretKeyReq;
class CSUpdateSecretKeyRes;
class CSKickOffNotify;
class CSPingReq;
class CSPingRes;

// ===================================================================

class CSGetGameSvrMinLoadReq : public ::google::protobuf::Message {
 public:
  CSGetGameSvrMinLoadReq();
  virtual ~CSGetGameSvrMinLoadReq();

  CSGetGameSvrMinLoadReq(const CSGetGameSvrMinLoadReq& from);

  inline CSGetGameSvrMinLoadReq& operator=(const CSGetGameSvrMinLoadReq& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CSGetGameSvrMinLoadReq& default_instance();

  void Swap(CSGetGameSvrMinLoadReq* other);

  // implements Message ----------------------------------------------

  CSGetGameSvrMinLoadReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CSGetGameSvrMinLoadReq& from);
  void MergeFrom(const CSGetGameSvrMinLoadReq& from);
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
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:cs.CSGetGameSvrMinLoadReq)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  friend void  protobuf_AddDesc_cs_5fgame_2eproto();
  friend void protobuf_AssignDesc_cs_5fgame_2eproto();
  friend void protobuf_ShutdownFile_cs_5fgame_2eproto();

  void InitAsDefaultInstance();
  static CSGetGameSvrMinLoadReq* default_instance_;
};
// -------------------------------------------------------------------

class CSGetGameSvrMinLoadRes_GameSvrHost : public ::google::protobuf::Message {
 public:
  CSGetGameSvrMinLoadRes_GameSvrHost();
  virtual ~CSGetGameSvrMinLoadRes_GameSvrHost();

  CSGetGameSvrMinLoadRes_GameSvrHost(const CSGetGameSvrMinLoadRes_GameSvrHost& from);

  inline CSGetGameSvrMinLoadRes_GameSvrHost& operator=(const CSGetGameSvrMinLoadRes_GameSvrHost& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CSGetGameSvrMinLoadRes_GameSvrHost& default_instance();

  void Swap(CSGetGameSvrMinLoadRes_GameSvrHost* other);

  // implements Message ----------------------------------------------

  CSGetGameSvrMinLoadRes_GameSvrHost* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CSGetGameSvrMinLoadRes_GameSvrHost& from);
  void MergeFrom(const CSGetGameSvrMinLoadRes_GameSvrHost& from);
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
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string Ip = 1;
  inline bool has_ip() const;
  inline void clear_ip();
  static const int kIpFieldNumber = 1;
  inline const ::std::string& ip() const;
  inline void set_ip(const ::std::string& value);
  inline void set_ip(const char* value);
  inline void set_ip(const char* value, size_t size);
  inline ::std::string* mutable_ip();
  inline ::std::string* release_ip();
  inline void set_allocated_ip(::std::string* ip);

  // required int32 Port = 2;
  inline bool has_port() const;
  inline void clear_port();
  static const int kPortFieldNumber = 2;
  inline ::google::protobuf::int32 port() const;
  inline void set_port(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:cs.CSGetGameSvrMinLoadRes.GameSvrHost)
 private:
  inline void set_has_ip();
  inline void clear_has_ip();
  inline void set_has_port();
  inline void clear_has_port();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* ip_;
  ::google::protobuf::int32 port_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_cs_5fgame_2eproto();
  friend void protobuf_AssignDesc_cs_5fgame_2eproto();
  friend void protobuf_ShutdownFile_cs_5fgame_2eproto();

  void InitAsDefaultInstance();
  static CSGetGameSvrMinLoadRes_GameSvrHost* default_instance_;
};
// -------------------------------------------------------------------

class CSGetGameSvrMinLoadRes : public ::google::protobuf::Message {
 public:
  CSGetGameSvrMinLoadRes();
  virtual ~CSGetGameSvrMinLoadRes();

  CSGetGameSvrMinLoadRes(const CSGetGameSvrMinLoadRes& from);

  inline CSGetGameSvrMinLoadRes& operator=(const CSGetGameSvrMinLoadRes& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CSGetGameSvrMinLoadRes& default_instance();

  void Swap(CSGetGameSvrMinLoadRes* other);

  // implements Message ----------------------------------------------

  CSGetGameSvrMinLoadRes* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CSGetGameSvrMinLoadRes& from);
  void MergeFrom(const CSGetGameSvrMinLoadRes& from);
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
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef CSGetGameSvrMinLoadRes_GameSvrHost GameSvrHost;

  // accessors -------------------------------------------------------

  // required int32 RetCode = 1;
  inline bool has_retcode() const;
  inline void clear_retcode();
  static const int kRetCodeFieldNumber = 1;
  inline ::google::protobuf::int32 retcode() const;
  inline void set_retcode(::google::protobuf::int32 value);

  // repeated .cs.CSGetGameSvrMinLoadRes.GameSvrHost Hosts = 2;
  inline int hosts_size() const;
  inline void clear_hosts();
  static const int kHostsFieldNumber = 2;
  inline const ::cs::CSGetGameSvrMinLoadRes_GameSvrHost& hosts(int index) const;
  inline ::cs::CSGetGameSvrMinLoadRes_GameSvrHost* mutable_hosts(int index);
  inline ::cs::CSGetGameSvrMinLoadRes_GameSvrHost* add_hosts();
  inline const ::google::protobuf::RepeatedPtrField< ::cs::CSGetGameSvrMinLoadRes_GameSvrHost >&
      hosts() const;
  inline ::google::protobuf::RepeatedPtrField< ::cs::CSGetGameSvrMinLoadRes_GameSvrHost >*
      mutable_hosts();

  // @@protoc_insertion_point(class_scope:cs.CSGetGameSvrMinLoadRes)
 private:
  inline void set_has_retcode();
  inline void clear_has_retcode();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::cs::CSGetGameSvrMinLoadRes_GameSvrHost > hosts_;
  ::google::protobuf::int32 retcode_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_cs_5fgame_2eproto();
  friend void protobuf_AssignDesc_cs_5fgame_2eproto();
  friend void protobuf_ShutdownFile_cs_5fgame_2eproto();

  void InitAsDefaultInstance();
  static CSGetGameSvrMinLoadRes* default_instance_;
};
// -------------------------------------------------------------------

class CSHeartbeatReq : public ::google::protobuf::Message {
 public:
  CSHeartbeatReq();
  virtual ~CSHeartbeatReq();

  CSHeartbeatReq(const CSHeartbeatReq& from);

  inline CSHeartbeatReq& operator=(const CSHeartbeatReq& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CSHeartbeatReq& default_instance();

  void Swap(CSHeartbeatReq* other);

  // implements Message ----------------------------------------------

  CSHeartbeatReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CSHeartbeatReq& from);
  void MergeFrom(const CSHeartbeatReq& from);
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
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:cs.CSHeartbeatReq)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  friend void  protobuf_AddDesc_cs_5fgame_2eproto();
  friend void protobuf_AssignDesc_cs_5fgame_2eproto();
  friend void protobuf_ShutdownFile_cs_5fgame_2eproto();

  void InitAsDefaultInstance();
  static CSHeartbeatReq* default_instance_;
};
// -------------------------------------------------------------------

class CSHeartbeatRes : public ::google::protobuf::Message {
 public:
  CSHeartbeatRes();
  virtual ~CSHeartbeatRes();

  CSHeartbeatRes(const CSHeartbeatRes& from);

  inline CSHeartbeatRes& operator=(const CSHeartbeatRes& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CSHeartbeatRes& default_instance();

  void Swap(CSHeartbeatRes* other);

  // implements Message ----------------------------------------------

  CSHeartbeatRes* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CSHeartbeatRes& from);
  void MergeFrom(const CSHeartbeatRes& from);
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
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 TickSec = 1;
  inline bool has_ticksec() const;
  inline void clear_ticksec();
  static const int kTickSecFieldNumber = 1;
  inline ::google::protobuf::uint32 ticksec() const;
  inline void set_ticksec(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:cs.CSHeartbeatRes)
 private:
  inline void set_has_ticksec();
  inline void clear_has_ticksec();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 ticksec_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_cs_5fgame_2eproto();
  friend void protobuf_AssignDesc_cs_5fgame_2eproto();
  friend void protobuf_ShutdownFile_cs_5fgame_2eproto();

  void InitAsDefaultInstance();
  static CSHeartbeatRes* default_instance_;
};
// -------------------------------------------------------------------

class CSUpdateSecretKeyReq : public ::google::protobuf::Message {
 public:
  CSUpdateSecretKeyReq();
  virtual ~CSUpdateSecretKeyReq();

  CSUpdateSecretKeyReq(const CSUpdateSecretKeyReq& from);

  inline CSUpdateSecretKeyReq& operator=(const CSUpdateSecretKeyReq& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CSUpdateSecretKeyReq& default_instance();

  void Swap(CSUpdateSecretKeyReq* other);

  // implements Message ----------------------------------------------

  CSUpdateSecretKeyReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CSUpdateSecretKeyReq& from);
  void MergeFrom(const CSUpdateSecretKeyReq& from);
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
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:cs.CSUpdateSecretKeyReq)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  friend void  protobuf_AddDesc_cs_5fgame_2eproto();
  friend void protobuf_AssignDesc_cs_5fgame_2eproto();
  friend void protobuf_ShutdownFile_cs_5fgame_2eproto();

  void InitAsDefaultInstance();
  static CSUpdateSecretKeyReq* default_instance_;
};
// -------------------------------------------------------------------

class CSUpdateSecretKeyRes : public ::google::protobuf::Message {
 public:
  CSUpdateSecretKeyRes();
  virtual ~CSUpdateSecretKeyRes();

  CSUpdateSecretKeyRes(const CSUpdateSecretKeyRes& from);

  inline CSUpdateSecretKeyRes& operator=(const CSUpdateSecretKeyRes& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CSUpdateSecretKeyRes& default_instance();

  void Swap(CSUpdateSecretKeyRes* other);

  // implements Message ----------------------------------------------

  CSUpdateSecretKeyRes* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CSUpdateSecretKeyRes& from);
  void MergeFrom(const CSUpdateSecretKeyRes& from);
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
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required bytes SecretKey = 1;
  inline bool has_secretkey() const;
  inline void clear_secretkey();
  static const int kSecretKeyFieldNumber = 1;
  inline const ::std::string& secretkey() const;
  inline void set_secretkey(const ::std::string& value);
  inline void set_secretkey(const char* value);
  inline void set_secretkey(const void* value, size_t size);
  inline ::std::string* mutable_secretkey();
  inline ::std::string* release_secretkey();
  inline void set_allocated_secretkey(::std::string* secretkey);

  // @@protoc_insertion_point(class_scope:cs.CSUpdateSecretKeyRes)
 private:
  inline void set_has_secretkey();
  inline void clear_has_secretkey();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* secretkey_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_cs_5fgame_2eproto();
  friend void protobuf_AssignDesc_cs_5fgame_2eproto();
  friend void protobuf_ShutdownFile_cs_5fgame_2eproto();

  void InitAsDefaultInstance();
  static CSUpdateSecretKeyRes* default_instance_;
};
// -------------------------------------------------------------------

class CSKickOffNotify : public ::google::protobuf::Message {
 public:
  CSKickOffNotify();
  virtual ~CSKickOffNotify();

  CSKickOffNotify(const CSKickOffNotify& from);

  inline CSKickOffNotify& operator=(const CSKickOffNotify& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CSKickOffNotify& default_instance();

  void Swap(CSKickOffNotify* other);

  // implements Message ----------------------------------------------

  CSKickOffNotify* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CSKickOffNotify& from);
  void MergeFrom(const CSKickOffNotify& from);
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
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:cs.CSKickOffNotify)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  friend void  protobuf_AddDesc_cs_5fgame_2eproto();
  friend void protobuf_AssignDesc_cs_5fgame_2eproto();
  friend void protobuf_ShutdownFile_cs_5fgame_2eproto();

  void InitAsDefaultInstance();
  static CSKickOffNotify* default_instance_;
};
// -------------------------------------------------------------------

class CSPingReq : public ::google::protobuf::Message {
 public:
  CSPingReq();
  virtual ~CSPingReq();

  CSPingReq(const CSPingReq& from);

  inline CSPingReq& operator=(const CSPingReq& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CSPingReq& default_instance();

  void Swap(CSPingReq* other);

  // implements Message ----------------------------------------------

  CSPingReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CSPingReq& from);
  void MergeFrom(const CSPingReq& from);
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
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 ClientTm = 1;
  inline bool has_clienttm() const;
  inline void clear_clienttm();
  static const int kClientTmFieldNumber = 1;
  inline ::google::protobuf::uint32 clienttm() const;
  inline void set_clienttm(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:cs.CSPingReq)
 private:
  inline void set_has_clienttm();
  inline void clear_has_clienttm();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 clienttm_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_cs_5fgame_2eproto();
  friend void protobuf_AssignDesc_cs_5fgame_2eproto();
  friend void protobuf_ShutdownFile_cs_5fgame_2eproto();

  void InitAsDefaultInstance();
  static CSPingReq* default_instance_;
};
// -------------------------------------------------------------------

class CSPingRes : public ::google::protobuf::Message {
 public:
  CSPingRes();
  virtual ~CSPingRes();

  CSPingRes(const CSPingRes& from);

  inline CSPingRes& operator=(const CSPingRes& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CSPingRes& default_instance();

  void Swap(CSPingRes* other);

  // implements Message ----------------------------------------------

  CSPingRes* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CSPingRes& from);
  void MergeFrom(const CSPingRes& from);
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
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 ClientTm = 1;
  inline bool has_clienttm() const;
  inline void clear_clienttm();
  static const int kClientTmFieldNumber = 1;
  inline ::google::protobuf::uint32 clienttm() const;
  inline void set_clienttm(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:cs.CSPingRes)
 private:
  inline void set_has_clienttm();
  inline void clear_has_clienttm();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 clienttm_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_cs_5fgame_2eproto();
  friend void protobuf_AssignDesc_cs_5fgame_2eproto();
  friend void protobuf_ShutdownFile_cs_5fgame_2eproto();

  void InitAsDefaultInstance();
  static CSPingRes* default_instance_;
};
// ===================================================================


// ===================================================================

// CSGetGameSvrMinLoadReq

// -------------------------------------------------------------------

// CSGetGameSvrMinLoadRes_GameSvrHost

// required string Ip = 1;
inline bool CSGetGameSvrMinLoadRes_GameSvrHost::has_ip() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::set_has_ip() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::clear_has_ip() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::clear_ip() {
  if (ip_ != &::google::protobuf::internal::kEmptyString) {
    ip_->clear();
  }
  clear_has_ip();
}
inline const ::std::string& CSGetGameSvrMinLoadRes_GameSvrHost::ip() const {
  return *ip_;
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::set_ip(const ::std::string& value) {
  set_has_ip();
  if (ip_ == &::google::protobuf::internal::kEmptyString) {
    ip_ = new ::std::string;
  }
  ip_->assign(value);
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::set_ip(const char* value) {
  set_has_ip();
  if (ip_ == &::google::protobuf::internal::kEmptyString) {
    ip_ = new ::std::string;
  }
  ip_->assign(value);
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::set_ip(const char* value, size_t size) {
  set_has_ip();
  if (ip_ == &::google::protobuf::internal::kEmptyString) {
    ip_ = new ::std::string;
  }
  ip_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CSGetGameSvrMinLoadRes_GameSvrHost::mutable_ip() {
  set_has_ip();
  if (ip_ == &::google::protobuf::internal::kEmptyString) {
    ip_ = new ::std::string;
  }
  return ip_;
}
inline ::std::string* CSGetGameSvrMinLoadRes_GameSvrHost::release_ip() {
  clear_has_ip();
  if (ip_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = ip_;
    ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::set_allocated_ip(::std::string* ip) {
  if (ip_ != &::google::protobuf::internal::kEmptyString) {
    delete ip_;
  }
  if (ip) {
    set_has_ip();
    ip_ = ip;
  } else {
    clear_has_ip();
    ip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required int32 Port = 2;
inline bool CSGetGameSvrMinLoadRes_GameSvrHost::has_port() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::set_has_port() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::clear_has_port() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::clear_port() {
  port_ = 0;
  clear_has_port();
}
inline ::google::protobuf::int32 CSGetGameSvrMinLoadRes_GameSvrHost::port() const {
  return port_;
}
inline void CSGetGameSvrMinLoadRes_GameSvrHost::set_port(::google::protobuf::int32 value) {
  set_has_port();
  port_ = value;
}

// -------------------------------------------------------------------

// CSGetGameSvrMinLoadRes

// required int32 RetCode = 1;
inline bool CSGetGameSvrMinLoadRes::has_retcode() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CSGetGameSvrMinLoadRes::set_has_retcode() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CSGetGameSvrMinLoadRes::clear_has_retcode() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CSGetGameSvrMinLoadRes::clear_retcode() {
  retcode_ = 0;
  clear_has_retcode();
}
inline ::google::protobuf::int32 CSGetGameSvrMinLoadRes::retcode() const {
  return retcode_;
}
inline void CSGetGameSvrMinLoadRes::set_retcode(::google::protobuf::int32 value) {
  set_has_retcode();
  retcode_ = value;
}

// repeated .cs.CSGetGameSvrMinLoadRes.GameSvrHost Hosts = 2;
inline int CSGetGameSvrMinLoadRes::hosts_size() const {
  return hosts_.size();
}
inline void CSGetGameSvrMinLoadRes::clear_hosts() {
  hosts_.Clear();
}
inline const ::cs::CSGetGameSvrMinLoadRes_GameSvrHost& CSGetGameSvrMinLoadRes::hosts(int index) const {
  return hosts_.Get(index);
}
inline ::cs::CSGetGameSvrMinLoadRes_GameSvrHost* CSGetGameSvrMinLoadRes::mutable_hosts(int index) {
  return hosts_.Mutable(index);
}
inline ::cs::CSGetGameSvrMinLoadRes_GameSvrHost* CSGetGameSvrMinLoadRes::add_hosts() {
  return hosts_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::cs::CSGetGameSvrMinLoadRes_GameSvrHost >&
CSGetGameSvrMinLoadRes::hosts() const {
  return hosts_;
}
inline ::google::protobuf::RepeatedPtrField< ::cs::CSGetGameSvrMinLoadRes_GameSvrHost >*
CSGetGameSvrMinLoadRes::mutable_hosts() {
  return &hosts_;
}

// -------------------------------------------------------------------

// CSHeartbeatReq

// -------------------------------------------------------------------

// CSHeartbeatRes

// required uint32 TickSec = 1;
inline bool CSHeartbeatRes::has_ticksec() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CSHeartbeatRes::set_has_ticksec() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CSHeartbeatRes::clear_has_ticksec() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CSHeartbeatRes::clear_ticksec() {
  ticksec_ = 0u;
  clear_has_ticksec();
}
inline ::google::protobuf::uint32 CSHeartbeatRes::ticksec() const {
  return ticksec_;
}
inline void CSHeartbeatRes::set_ticksec(::google::protobuf::uint32 value) {
  set_has_ticksec();
  ticksec_ = value;
}

// -------------------------------------------------------------------

// CSUpdateSecretKeyReq

// -------------------------------------------------------------------

// CSUpdateSecretKeyRes

// required bytes SecretKey = 1;
inline bool CSUpdateSecretKeyRes::has_secretkey() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CSUpdateSecretKeyRes::set_has_secretkey() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CSUpdateSecretKeyRes::clear_has_secretkey() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CSUpdateSecretKeyRes::clear_secretkey() {
  if (secretkey_ != &::google::protobuf::internal::kEmptyString) {
    secretkey_->clear();
  }
  clear_has_secretkey();
}
inline const ::std::string& CSUpdateSecretKeyRes::secretkey() const {
  return *secretkey_;
}
inline void CSUpdateSecretKeyRes::set_secretkey(const ::std::string& value) {
  set_has_secretkey();
  if (secretkey_ == &::google::protobuf::internal::kEmptyString) {
    secretkey_ = new ::std::string;
  }
  secretkey_->assign(value);
}
inline void CSUpdateSecretKeyRes::set_secretkey(const char* value) {
  set_has_secretkey();
  if (secretkey_ == &::google::protobuf::internal::kEmptyString) {
    secretkey_ = new ::std::string;
  }
  secretkey_->assign(value);
}
inline void CSUpdateSecretKeyRes::set_secretkey(const void* value, size_t size) {
  set_has_secretkey();
  if (secretkey_ == &::google::protobuf::internal::kEmptyString) {
    secretkey_ = new ::std::string;
  }
  secretkey_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CSUpdateSecretKeyRes::mutable_secretkey() {
  set_has_secretkey();
  if (secretkey_ == &::google::protobuf::internal::kEmptyString) {
    secretkey_ = new ::std::string;
  }
  return secretkey_;
}
inline ::std::string* CSUpdateSecretKeyRes::release_secretkey() {
  clear_has_secretkey();
  if (secretkey_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = secretkey_;
    secretkey_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CSUpdateSecretKeyRes::set_allocated_secretkey(::std::string* secretkey) {
  if (secretkey_ != &::google::protobuf::internal::kEmptyString) {
    delete secretkey_;
  }
  if (secretkey) {
    set_has_secretkey();
    secretkey_ = secretkey;
  } else {
    clear_has_secretkey();
    secretkey_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// CSKickOffNotify

// -------------------------------------------------------------------

// CSPingReq

// required uint32 ClientTm = 1;
inline bool CSPingReq::has_clienttm() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CSPingReq::set_has_clienttm() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CSPingReq::clear_has_clienttm() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CSPingReq::clear_clienttm() {
  clienttm_ = 0u;
  clear_has_clienttm();
}
inline ::google::protobuf::uint32 CSPingReq::clienttm() const {
  return clienttm_;
}
inline void CSPingReq::set_clienttm(::google::protobuf::uint32 value) {
  set_has_clienttm();
  clienttm_ = value;
}

// -------------------------------------------------------------------

// CSPingRes

// required uint32 ClientTm = 1;
inline bool CSPingRes::has_clienttm() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CSPingRes::set_has_clienttm() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CSPingRes::clear_has_clienttm() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CSPingRes::clear_clienttm() {
  clienttm_ = 0u;
  clear_has_clienttm();
}
inline ::google::protobuf::uint32 CSPingRes::clienttm() const {
  return clienttm_;
}
inline void CSPingRes::set_clienttm(::google::protobuf::uint32 value) {
  set_has_clienttm();
  clienttm_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace cs

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_cs_5fgame_2eproto__INCLUDED