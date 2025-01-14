/* Generated from /usr/src/crypto/heimdal/lib/asn1/pkinit.asn1 */
/* Do not edit */

#ifndef __pkinit_asn1_h__
#define __pkinit_asn1_h__

#include <stddef.h>
#include <time.h>

#ifndef __asn1_common_definitions__
#define __asn1_common_definitions__

typedef struct heim_integer {
  size_t length;
  void *data;
  int negative;
} heim_integer;

typedef struct heim_octet_string {
  size_t length;
  void *data;
} heim_octet_string;

typedef char *heim_general_string;

typedef char *heim_utf8_string;

typedef struct heim_octet_string heim_printable_string;

typedef struct heim_octet_string heim_ia5_string;

typedef struct heim_bmp_string {
  size_t length;
  uint16_t *data;
} heim_bmp_string;

typedef struct heim_universal_string {
  size_t length;
  uint32_t *data;
} heim_universal_string;

typedef char *heim_visible_string;

typedef struct heim_oid {
  size_t length;
  unsigned *components;
} heim_oid;

typedef struct heim_bit_string {
  size_t length;
  void *data;
} heim_bit_string;

typedef struct heim_octet_string heim_any;
typedef struct heim_octet_string heim_any_set;

#define ASN1_MALLOC_ENCODE(T, B, BL, S, L, R)                  \
  do {                                                         \
    (BL) = length_##T((S));                                    \
    (B) = malloc((BL));                                        \
    if((B) == NULL) {                                          \
      (R) = ENOMEM;                                            \
    } else {                                                   \
      (R) = encode_##T(((unsigned char*)(B)) + (BL) - 1, (BL), \
                       (S), (L));                              \
      if((R) != 0) {                                           \
        free((B));                                             \
        (B) = NULL;                                            \
      }                                                        \
    }                                                          \
  } while (0)

#ifdef _WIN32
#ifndef ASN1_LIB
#define ASN1EXP  __declspec(dllimport)
#else
#define ASN1EXP
#endif
#define ASN1CALL __stdcall
#else
#define ASN1EXP
#define ASN1CALL
#endif
struct units;

#endif

#include <krb5_asn1.h>
#include <cms_asn1.h>
#include <rfc2459_asn1.h>
#include <heim_asn1.h>
/* OBJECT IDENTIFIER id-pkinit ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) pkinit(3) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkinit;
#define ASN1_OID_ID_PKINIT (&asn1_oid_id_pkinit)

/* OBJECT IDENTIFIER id-pkauthdata ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) pkinit(3) label-less(1) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkauthdata;
#define ASN1_OID_ID_PKAUTHDATA (&asn1_oid_id_pkauthdata)

/* OBJECT IDENTIFIER id-pkdhkeydata ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) pkinit(3) label-less(2) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkdhkeydata;
#define ASN1_OID_ID_PKDHKEYDATA (&asn1_oid_id_pkdhkeydata)

/* OBJECT IDENTIFIER id-pkrkeydata ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) pkinit(3) label-less(3) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkrkeydata;
#define ASN1_OID_ID_PKRKEYDATA (&asn1_oid_id_pkrkeydata)

/* OBJECT IDENTIFIER id-pkekuoid ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) pkinit(3) label-less(4) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkekuoid;
#define ASN1_OID_ID_PKEKUOID (&asn1_oid_id_pkekuoid)

/* OBJECT IDENTIFIER id-pkkdcekuoid ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) pkinit(3) label-less(5) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkkdcekuoid;
#define ASN1_OID_ID_PKKDCEKUOID (&asn1_oid_id_pkkdcekuoid)

/* OBJECT IDENTIFIER id-pkinit-kdf ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) pkinit(3) label-less(6) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkinit_kdf;
#define ASN1_OID_ID_PKINIT_KDF (&asn1_oid_id_pkinit_kdf)

/* OBJECT IDENTIFIER id-pkinit-kdf-ah-sha1 ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) pkinit(3) label-less(6) label-less(1) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkinit_kdf_ah_sha1;
#define ASN1_OID_ID_PKINIT_KDF_AH_SHA1 (&asn1_oid_id_pkinit_kdf_ah_sha1)

/* OBJECT IDENTIFIER id-pkinit-kdf-ah-sha256 ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) pkinit(3) label-less(6) label-less(2) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkinit_kdf_ah_sha256;
#define ASN1_OID_ID_PKINIT_KDF_AH_SHA256 (&asn1_oid_id_pkinit_kdf_ah_sha256)

/* OBJECT IDENTIFIER id-pkinit-kdf-ah-sha512 ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) pkinit(3) label-less(6) label-less(3) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkinit_kdf_ah_sha512;
#define ASN1_OID_ID_PKINIT_KDF_AH_SHA512 (&asn1_oid_id_pkinit_kdf_ah_sha512)

/* OBJECT IDENTIFIER id-pkinit-san ::= { iso(1) org(3) dod(6) internet(1) security(5) kerberosv5(2) x509-sanan(2) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkinit_san;
#define ASN1_OID_ID_PKINIT_SAN (&asn1_oid_id_pkinit_san)

/* OBJECT IDENTIFIER id-pkinit-ms-eku ::= { iso(1) org(3) dod(6) internet(1) private(4) enterprise(1) microsoft(311) label-less(20) label-less(2) label-less(2) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkinit_ms_eku;
#define ASN1_OID_ID_PKINIT_MS_EKU (&asn1_oid_id_pkinit_ms_eku)

/* OBJECT IDENTIFIER id-pkinit-ms-san ::= { iso(1) org(3) dod(6) internet(1) private(4) enterprise(1) microsoft(311) label-less(20) label-less(2) label-less(3) } */
extern ASN1EXP const heim_oid asn1_oid_id_pkinit_ms_san;
#define ASN1_OID_ID_PKINIT_MS_SAN (&asn1_oid_id_pkinit_ms_san)

/*
MS-UPN-SAN ::= UTF8String
*/

typedef heim_utf8_string MS_UPN_SAN;

ASN1EXP int    ASN1CALL decode_MS_UPN_SAN(const unsigned char *, size_t, MS_UPN_SAN *, size_t *);
ASN1EXP int    ASN1CALL encode_MS_UPN_SAN(unsigned char *, size_t, const MS_UPN_SAN *, size_t *);
ASN1EXP size_t ASN1CALL length_MS_UPN_SAN(const MS_UPN_SAN *);
ASN1EXP int    ASN1CALL copy_MS_UPN_SAN  (const MS_UPN_SAN *, MS_UPN_SAN *);
ASN1EXP void   ASN1CALL free_MS_UPN_SAN  (MS_UPN_SAN *);


enum { pa_pk_as_req = 16 };

enum { pa_pk_as_rep = 17 };

enum { td_trusted_certifiers = 104 };

enum { td_invalid_certificates = 105 };

enum { td_dh_parameters = 109 };

/*
DHNonce ::= OCTET STRING
*/

typedef heim_octet_string DHNonce;

ASN1EXP int    ASN1CALL decode_DHNonce(const unsigned char *, size_t, DHNonce *, size_t *);
ASN1EXP int    ASN1CALL encode_DHNonce(unsigned char *, size_t, const DHNonce *, size_t *);
ASN1EXP size_t ASN1CALL length_DHNonce(const DHNonce *);
ASN1EXP int    ASN1CALL copy_DHNonce  (const DHNonce *, DHNonce *);
ASN1EXP void   ASN1CALL free_DHNonce  (DHNonce *);


/*
KDFAlgorithmId ::= SEQUENCE {
  kdf-id          [0]   OBJECT IDENTIFIER,
  ...,
}
*/

typedef struct KDFAlgorithmId {
  heim_oid kdf_id;
} KDFAlgorithmId;

ASN1EXP int    ASN1CALL decode_KDFAlgorithmId(const unsigned char *, size_t, KDFAlgorithmId *, size_t *);
ASN1EXP int    ASN1CALL encode_KDFAlgorithmId(unsigned char *, size_t, const KDFAlgorithmId *, size_t *);
ASN1EXP size_t ASN1CALL length_KDFAlgorithmId(const KDFAlgorithmId *);
ASN1EXP int    ASN1CALL copy_KDFAlgorithmId  (const KDFAlgorithmId *, KDFAlgorithmId *);
ASN1EXP void   ASN1CALL free_KDFAlgorithmId  (KDFAlgorithmId *);


/*
TrustedCA ::= SEQUENCE {
  caName                    [0] IMPLICIT OCTET STRING,
  certificateSerialNumber   [1] INTEGER OPTIONAL,
  subjectKeyIdentifier      [2] OCTET STRING OPTIONAL,
  ...,
}
*/

typedef struct TrustedCA {
  heim_octet_string caName;
  heim_integer *certificateSerialNumber;
  heim_octet_string *subjectKeyIdentifier;
} TrustedCA;

ASN1EXP int    ASN1CALL decode_TrustedCA(const unsigned char *, size_t, TrustedCA *, size_t *);
ASN1EXP int    ASN1CALL encode_TrustedCA(unsigned char *, size_t, const TrustedCA *, size_t *);
ASN1EXP size_t ASN1CALL length_TrustedCA(const TrustedCA *);
ASN1EXP int    ASN1CALL copy_TrustedCA  (const TrustedCA *, TrustedCA *);
ASN1EXP void   ASN1CALL free_TrustedCA  (TrustedCA *);


/*
ExternalPrincipalIdentifier ::= SEQUENCE {
  subjectName             [0] IMPLICIT OCTET STRING OPTIONAL,
  issuerAndSerialNumber   [1] IMPLICIT OCTET STRING OPTIONAL,
  subjectKeyIdentifier    [2] IMPLICIT OCTET STRING OPTIONAL,
  ...,
}
*/

typedef struct ExternalPrincipalIdentifier {
  heim_octet_string *subjectName;
  heim_octet_string *issuerAndSerialNumber;
  heim_octet_string *subjectKeyIdentifier;
} ExternalPrincipalIdentifier;

ASN1EXP int    ASN1CALL decode_ExternalPrincipalIdentifier(const unsigned char *, size_t, ExternalPrincipalIdentifier *, size_t *);
ASN1EXP int    ASN1CALL encode_ExternalPrincipalIdentifier(unsigned char *, size_t, const ExternalPrincipalIdentifier *, size_t *);
ASN1EXP size_t ASN1CALL length_ExternalPrincipalIdentifier(const ExternalPrincipalIdentifier *);
ASN1EXP int    ASN1CALL copy_ExternalPrincipalIdentifier  (const ExternalPrincipalIdentifier *, ExternalPrincipalIdentifier *);
ASN1EXP void   ASN1CALL free_ExternalPrincipalIdentifier  (ExternalPrincipalIdentifier *);


/*
ExternalPrincipalIdentifiers ::= SEQUENCE OF ExternalPrincipalIdentifier
*/

typedef struct ExternalPrincipalIdentifiers {
  unsigned int len;
  ExternalPrincipalIdentifier *val;
} ExternalPrincipalIdentifiers;

ASN1EXP int    ASN1CALL decode_ExternalPrincipalIdentifiers(const unsigned char *, size_t, ExternalPrincipalIdentifiers *, size_t *);
ASN1EXP int    ASN1CALL encode_ExternalPrincipalIdentifiers(unsigned char *, size_t, const ExternalPrincipalIdentifiers *, size_t *);
ASN1EXP size_t ASN1CALL length_ExternalPrincipalIdentifiers(const ExternalPrincipalIdentifiers *);
ASN1EXP int    ASN1CALL copy_ExternalPrincipalIdentifiers  (const ExternalPrincipalIdentifiers *, ExternalPrincipalIdentifiers *);
ASN1EXP void   ASN1CALL free_ExternalPrincipalIdentifiers  (ExternalPrincipalIdentifiers *);


/*
PA-PK-AS-REQ ::= SEQUENCE {
  signedAuthPack      [0] IMPLICIT OCTET STRING,
  trustedCertifiers   [1] ExternalPrincipalIdentifiers OPTIONAL,
  kdcPkId             [2] IMPLICIT OCTET STRING OPTIONAL,
  ...,
}
*/

typedef struct PA_PK_AS_REQ {
  heim_octet_string signedAuthPack;
  ExternalPrincipalIdentifiers *trustedCertifiers;
  heim_octet_string *kdcPkId;
} PA_PK_AS_REQ;

ASN1EXP int    ASN1CALL decode_PA_PK_AS_REQ(const unsigned char *, size_t, PA_PK_AS_REQ *, size_t *);
ASN1EXP int    ASN1CALL encode_PA_PK_AS_REQ(unsigned char *, size_t, const PA_PK_AS_REQ *, size_t *);
ASN1EXP size_t ASN1CALL length_PA_PK_AS_REQ(const PA_PK_AS_REQ *);
ASN1EXP int    ASN1CALL copy_PA_PK_AS_REQ  (const PA_PK_AS_REQ *, PA_PK_AS_REQ *);
ASN1EXP void   ASN1CALL free_PA_PK_AS_REQ  (PA_PK_AS_REQ *);


/*
PKAuthenticator ::= SEQUENCE {
  cusec           [0] INTEGER,
  ctime           [1] KerberosTime,
  nonce           [2] INTEGER (0..2147483647),
  paChecksum      [3] OCTET STRING OPTIONAL,
  ...,
}
*/

typedef struct PKAuthenticator {
  heim_integer cusec;
  KerberosTime ctime;
  unsigned int nonce;
  heim_octet_string *paChecksum;
} PKAuthenticator;

ASN1EXP int    ASN1CALL decode_PKAuthenticator(const unsigned char *, size_t, PKAuthenticator *, size_t *);
ASN1EXP int    ASN1CALL encode_PKAuthenticator(unsigned char *, size_t, const PKAuthenticator *, size_t *);
ASN1EXP size_t ASN1CALL length_PKAuthenticator(const PKAuthenticator *);
ASN1EXP int    ASN1CALL copy_PKAuthenticator  (const PKAuthenticator *, PKAuthenticator *);
ASN1EXP void   ASN1CALL free_PKAuthenticator  (PKAuthenticator *);


/*
AuthPack ::= SEQUENCE {
  pkAuthenticator     [0] PKAuthenticator,
  clientPublicValue   [1] SubjectPublicKeyInfo OPTIONAL,
  supportedCMSTypes   [2] SEQUENCE OF AlgorithmIdentifier OPTIONAL,
  clientDHNonce       [3] DHNonce OPTIONAL,
  ...,
  supportedKDFs       [4] SEQUENCE OF KDFAlgorithmId OPTIONAL,
  ...,
}
*/

typedef struct AuthPack {
  PKAuthenticator pkAuthenticator;
  SubjectPublicKeyInfo *clientPublicValue;
  struct AuthPack_supportedCMSTypes {
    unsigned int len;
    AlgorithmIdentifier *val;
  } *supportedCMSTypes;
  DHNonce *clientDHNonce;
  struct AuthPack_supportedKDFs {
    unsigned int len;
    KDFAlgorithmId *val;
  } *supportedKDFs;
} AuthPack;

ASN1EXP int    ASN1CALL decode_AuthPack(const unsigned char *, size_t, AuthPack *, size_t *);
ASN1EXP int    ASN1CALL encode_AuthPack(unsigned char *, size_t, const AuthPack *, size_t *);
ASN1EXP size_t ASN1CALL length_AuthPack(const AuthPack *);
ASN1EXP int    ASN1CALL copy_AuthPack  (const AuthPack *, AuthPack *);
ASN1EXP void   ASN1CALL free_AuthPack  (AuthPack *);


/*
TD-TRUSTED-CERTIFIERS ::= ExternalPrincipalIdentifiers
*/

typedef ExternalPrincipalIdentifiers TD_TRUSTED_CERTIFIERS;

ASN1EXP int    ASN1CALL decode_TD_TRUSTED_CERTIFIERS(const unsigned char *, size_t, TD_TRUSTED_CERTIFIERS *, size_t *);
ASN1EXP int    ASN1CALL encode_TD_TRUSTED_CERTIFIERS(unsigned char *, size_t, const TD_TRUSTED_CERTIFIERS *, size_t *);
ASN1EXP size_t ASN1CALL length_TD_TRUSTED_CERTIFIERS(const TD_TRUSTED_CERTIFIERS *);
ASN1EXP int    ASN1CALL copy_TD_TRUSTED_CERTIFIERS  (const TD_TRUSTED_CERTIFIERS *, TD_TRUSTED_CERTIFIERS *);
ASN1EXP void   ASN1CALL free_TD_TRUSTED_CERTIFIERS  (TD_TRUSTED_CERTIFIERS *);


/*
TD-INVALID-CERTIFICATES ::= ExternalPrincipalIdentifiers
*/

typedef ExternalPrincipalIdentifiers TD_INVALID_CERTIFICATES;

ASN1EXP int    ASN1CALL decode_TD_INVALID_CERTIFICATES(const unsigned char *, size_t, TD_INVALID_CERTIFICATES *, size_t *);
ASN1EXP int    ASN1CALL encode_TD_INVALID_CERTIFICATES(unsigned char *, size_t, const TD_INVALID_CERTIFICATES *, size_t *);
ASN1EXP size_t ASN1CALL length_TD_INVALID_CERTIFICATES(const TD_INVALID_CERTIFICATES *);
ASN1EXP int    ASN1CALL copy_TD_INVALID_CERTIFICATES  (const TD_INVALID_CERTIFICATES *, TD_INVALID_CERTIFICATES *);
ASN1EXP void   ASN1CALL free_TD_INVALID_CERTIFICATES  (TD_INVALID_CERTIFICATES *);


/*
KRB5PrincipalName ::= SEQUENCE {
  realm           [0] Realm,
  principalName   [1] PrincipalName,
}
*/

typedef struct KRB5PrincipalName {
  Realm realm;
  PrincipalName principalName;
} KRB5PrincipalName;

ASN1EXP int    ASN1CALL decode_KRB5PrincipalName(const unsigned char *, size_t, KRB5PrincipalName *, size_t *);
ASN1EXP int    ASN1CALL encode_KRB5PrincipalName(unsigned char *, size_t, const KRB5PrincipalName *, size_t *);
ASN1EXP size_t ASN1CALL length_KRB5PrincipalName(const KRB5PrincipalName *);
ASN1EXP int    ASN1CALL copy_KRB5PrincipalName  (const KRB5PrincipalName *, KRB5PrincipalName *);
ASN1EXP void   ASN1CALL free_KRB5PrincipalName  (KRB5PrincipalName *);


/*
AD-INITIAL-VERIFIED-CAS ::= SEQUENCE OF ExternalPrincipalIdentifier
*/

typedef struct AD_INITIAL_VERIFIED_CAS {
  unsigned int len;
  ExternalPrincipalIdentifier *val;
} AD_INITIAL_VERIFIED_CAS;

ASN1EXP int    ASN1CALL decode_AD_INITIAL_VERIFIED_CAS(const unsigned char *, size_t, AD_INITIAL_VERIFIED_CAS *, size_t *);
ASN1EXP int    ASN1CALL encode_AD_INITIAL_VERIFIED_CAS(unsigned char *, size_t, const AD_INITIAL_VERIFIED_CAS *, size_t *);
ASN1EXP size_t ASN1CALL length_AD_INITIAL_VERIFIED_CAS(const AD_INITIAL_VERIFIED_CAS *);
ASN1EXP int    ASN1CALL copy_AD_INITIAL_VERIFIED_CAS  (const AD_INITIAL_VERIFIED_CAS *, AD_INITIAL_VERIFIED_CAS *);
ASN1EXP void   ASN1CALL free_AD_INITIAL_VERIFIED_CAS  (AD_INITIAL_VERIFIED_CAS *);


/*
DHRepInfo ::= SEQUENCE {
  dhSignedData    [0] IMPLICIT OCTET STRING,
  serverDHNonce   [1] DHNonce OPTIONAL,
  ...,
  kdf             [2] KDFAlgorithmId OPTIONAL,
  ...,
}
*/

typedef struct DHRepInfo {
  heim_octet_string dhSignedData;
  DHNonce *serverDHNonce;
  KDFAlgorithmId *kdf;
} DHRepInfo;

ASN1EXP int    ASN1CALL decode_DHRepInfo(const unsigned char *, size_t, DHRepInfo *, size_t *);
ASN1EXP int    ASN1CALL encode_DHRepInfo(unsigned char *, size_t, const DHRepInfo *, size_t *);
ASN1EXP size_t ASN1CALL length_DHRepInfo(const DHRepInfo *);
ASN1EXP int    ASN1CALL copy_DHRepInfo  (const DHRepInfo *, DHRepInfo *);
ASN1EXP void   ASN1CALL free_DHRepInfo  (DHRepInfo *);


/*
PA-PK-AS-REP ::= CHOICE {
  dhInfo          [0] DHRepInfo,
  encKeyPack      [1] IMPLICIT OCTET STRING,
  ...,
}
*/

typedef struct PA_PK_AS_REP {
  enum {
    choice_PA_PK_AS_REP_asn1_ellipsis = 0,
    choice_PA_PK_AS_REP_dhInfo,
    choice_PA_PK_AS_REP_encKeyPack
    /* ... */
  } element;
  union {
    DHRepInfo dhInfo;
    heim_octet_string encKeyPack;
    heim_octet_string asn1_ellipsis;
  } u;
} PA_PK_AS_REP;

ASN1EXP int    ASN1CALL decode_PA_PK_AS_REP(const unsigned char *, size_t, PA_PK_AS_REP *, size_t *);
ASN1EXP int    ASN1CALL encode_PA_PK_AS_REP(unsigned char *, size_t, const PA_PK_AS_REP *, size_t *);
ASN1EXP size_t ASN1CALL length_PA_PK_AS_REP(const PA_PK_AS_REP *);
ASN1EXP int    ASN1CALL copy_PA_PK_AS_REP  (const PA_PK_AS_REP *, PA_PK_AS_REP *);
ASN1EXP void   ASN1CALL free_PA_PK_AS_REP  (PA_PK_AS_REP *);


/*
KDCDHKeyInfo ::= SEQUENCE {
  subjectPublicKey   [0]   BIT STRING {
  },
  nonce              [1] INTEGER (0..2147483647),
  dhKeyExpiration    [2] KerberosTime OPTIONAL,
  ...,
}
*/

typedef struct KDCDHKeyInfo {
  heim_bit_string subjectPublicKey;
  unsigned int nonce;
  KerberosTime *dhKeyExpiration;
} KDCDHKeyInfo;

ASN1EXP int    ASN1CALL decode_KDCDHKeyInfo(const unsigned char *, size_t, KDCDHKeyInfo *, size_t *);
ASN1EXP int    ASN1CALL encode_KDCDHKeyInfo(unsigned char *, size_t, const KDCDHKeyInfo *, size_t *);
ASN1EXP size_t ASN1CALL length_KDCDHKeyInfo(const KDCDHKeyInfo *);
ASN1EXP int    ASN1CALL copy_KDCDHKeyInfo  (const KDCDHKeyInfo *, KDCDHKeyInfo *);
ASN1EXP void   ASN1CALL free_KDCDHKeyInfo  (KDCDHKeyInfo *);


/*
ReplyKeyPack ::= SEQUENCE {
  replyKey        [0] EncryptionKey,
  asChecksum      [1] Checksum,
  ...,
}
*/

typedef struct ReplyKeyPack {
  EncryptionKey replyKey;
  Checksum asChecksum;
} ReplyKeyPack;

ASN1EXP int    ASN1CALL decode_ReplyKeyPack(const unsigned char *, size_t, ReplyKeyPack *, size_t *);
ASN1EXP int    ASN1CALL encode_ReplyKeyPack(unsigned char *, size_t, const ReplyKeyPack *, size_t *);
ASN1EXP size_t ASN1CALL length_ReplyKeyPack(const ReplyKeyPack *);
ASN1EXP int    ASN1CALL copy_ReplyKeyPack  (const ReplyKeyPack *, ReplyKeyPack *);
ASN1EXP void   ASN1CALL free_ReplyKeyPack  (ReplyKeyPack *);


/*
TD-DH-PARAMETERS ::= SEQUENCE OF AlgorithmIdentifier
*/

typedef struct TD_DH_PARAMETERS {
  unsigned int len;
  AlgorithmIdentifier *val;
} TD_DH_PARAMETERS;

ASN1EXP int    ASN1CALL decode_TD_DH_PARAMETERS(const unsigned char *, size_t, TD_DH_PARAMETERS *, size_t *);
ASN1EXP int    ASN1CALL encode_TD_DH_PARAMETERS(unsigned char *, size_t, const TD_DH_PARAMETERS *, size_t *);
ASN1EXP size_t ASN1CALL length_TD_DH_PARAMETERS(const TD_DH_PARAMETERS *);
ASN1EXP int    ASN1CALL copy_TD_DH_PARAMETERS  (const TD_DH_PARAMETERS *, TD_DH_PARAMETERS *);
ASN1EXP void   ASN1CALL free_TD_DH_PARAMETERS  (TD_DH_PARAMETERS *);


/*
PKAuthenticator-Win2k ::= SEQUENCE {
  kdcName         [0] PrincipalName,
  kdcRealm        [1] Realm,
  cusec           [2] INTEGER (0..2147483647),
  ctime           [3] KerberosTime,
  nonce           [4] INTEGER (-2147483648..2147483647),
}
*/

typedef struct PKAuthenticator_Win2k {
  PrincipalName kdcName;
  Realm kdcRealm;
  unsigned int cusec;
  KerberosTime ctime;
  int nonce;
} PKAuthenticator_Win2k;

ASN1EXP int    ASN1CALL decode_PKAuthenticator_Win2k(const unsigned char *, size_t, PKAuthenticator_Win2k *, size_t *);
ASN1EXP int    ASN1CALL encode_PKAuthenticator_Win2k(unsigned char *, size_t, const PKAuthenticator_Win2k *, size_t *);
ASN1EXP size_t ASN1CALL length_PKAuthenticator_Win2k(const PKAuthenticator_Win2k *);
ASN1EXP int    ASN1CALL copy_PKAuthenticator_Win2k  (const PKAuthenticator_Win2k *, PKAuthenticator_Win2k *);
ASN1EXP void   ASN1CALL free_PKAuthenticator_Win2k  (PKAuthenticator_Win2k *);


/*
AuthPack-Win2k ::= SEQUENCE {
  pkAuthenticator     [0] PKAuthenticator-Win2k,
  clientPublicValue   [1] SubjectPublicKeyInfo OPTIONAL,
}
*/

typedef struct AuthPack_Win2k {
  PKAuthenticator_Win2k pkAuthenticator;
  SubjectPublicKeyInfo *clientPublicValue;
} AuthPack_Win2k;

ASN1EXP int    ASN1CALL decode_AuthPack_Win2k(const unsigned char *, size_t, AuthPack_Win2k *, size_t *);
ASN1EXP int    ASN1CALL encode_AuthPack_Win2k(unsigned char *, size_t, const AuthPack_Win2k *, size_t *);
ASN1EXP size_t ASN1CALL length_AuthPack_Win2k(const AuthPack_Win2k *);
ASN1EXP int    ASN1CALL copy_AuthPack_Win2k  (const AuthPack_Win2k *, AuthPack_Win2k *);
ASN1EXP void   ASN1CALL free_AuthPack_Win2k  (AuthPack_Win2k *);


/*
TrustedCA-Win2k ::= CHOICE {
  caName            [1] heim_any,
  issuerAndSerial   [2] IssuerAndSerialNumber,
}
*/

typedef struct TrustedCA_Win2k {
  enum {
    choice_TrustedCA_Win2k_caName = 1,
    choice_TrustedCA_Win2k_issuerAndSerial
  } element;
  union {
    heim_any caName;
    IssuerAndSerialNumber issuerAndSerial;
  } u;
} TrustedCA_Win2k;

ASN1EXP int    ASN1CALL decode_TrustedCA_Win2k(const unsigned char *, size_t, TrustedCA_Win2k *, size_t *);
ASN1EXP int    ASN1CALL encode_TrustedCA_Win2k(unsigned char *, size_t, const TrustedCA_Win2k *, size_t *);
ASN1EXP size_t ASN1CALL length_TrustedCA_Win2k(const TrustedCA_Win2k *);
ASN1EXP int    ASN1CALL copy_TrustedCA_Win2k  (const TrustedCA_Win2k *, TrustedCA_Win2k *);
ASN1EXP void   ASN1CALL free_TrustedCA_Win2k  (TrustedCA_Win2k *);


/*
PA-PK-AS-REQ-Win2k ::= SEQUENCE {
  signed-auth-pack     [0] IMPLICIT OCTET STRING,
  trusted-certifiers   [2] SEQUENCE OF TrustedCA-Win2k OPTIONAL,
  kdc-cert             [3] IMPLICIT OCTET STRING OPTIONAL,
  encryption-cert      [4] IMPLICIT OCTET STRING OPTIONAL,
}
*/

typedef struct PA_PK_AS_REQ_Win2k {
  heim_octet_string signed_auth_pack;
  struct PA_PK_AS_REQ_Win2k_trusted_certifiers {
    unsigned int len;
    TrustedCA_Win2k *val;
  } *trusted_certifiers;
  heim_octet_string *kdc_cert;
  heim_octet_string *encryption_cert;
} PA_PK_AS_REQ_Win2k;

ASN1EXP int    ASN1CALL decode_PA_PK_AS_REQ_Win2k(const unsigned char *, size_t, PA_PK_AS_REQ_Win2k *, size_t *);
ASN1EXP int    ASN1CALL encode_PA_PK_AS_REQ_Win2k(unsigned char *, size_t, const PA_PK_AS_REQ_Win2k *, size_t *);
ASN1EXP size_t ASN1CALL length_PA_PK_AS_REQ_Win2k(const PA_PK_AS_REQ_Win2k *);
ASN1EXP int    ASN1CALL copy_PA_PK_AS_REQ_Win2k  (const PA_PK_AS_REQ_Win2k *, PA_PK_AS_REQ_Win2k *);
ASN1EXP void   ASN1CALL free_PA_PK_AS_REQ_Win2k  (PA_PK_AS_REQ_Win2k *);


/*
PA-PK-AS-REP-Win2k ::= CHOICE {
  dhSignedData    [0] IMPLICIT OCTET STRING,
  encKeyPack      [1] IMPLICIT OCTET STRING,
}
*/

typedef struct PA_PK_AS_REP_Win2k {
  enum {
    choice_PA_PK_AS_REP_Win2k_dhSignedData = 1,
    choice_PA_PK_AS_REP_Win2k_encKeyPack
  } element;
  union {
    heim_octet_string dhSignedData;
    heim_octet_string encKeyPack;
  } u;
} PA_PK_AS_REP_Win2k;

ASN1EXP int    ASN1CALL decode_PA_PK_AS_REP_Win2k(const unsigned char *, size_t, PA_PK_AS_REP_Win2k *, size_t *);
ASN1EXP int    ASN1CALL encode_PA_PK_AS_REP_Win2k(unsigned char *, size_t, const PA_PK_AS_REP_Win2k *, size_t *);
ASN1EXP size_t ASN1CALL length_PA_PK_AS_REP_Win2k(const PA_PK_AS_REP_Win2k *);
ASN1EXP int    ASN1CALL copy_PA_PK_AS_REP_Win2k  (const PA_PK_AS_REP_Win2k *, PA_PK_AS_REP_Win2k *);
ASN1EXP void   ASN1CALL free_PA_PK_AS_REP_Win2k  (PA_PK_AS_REP_Win2k *);


/*
KDCDHKeyInfo-Win2k ::= SEQUENCE {
  nonce              [0] INTEGER (-2147483648..2147483647),
  subjectPublicKey   [2]   BIT STRING {
  },
}
*/

typedef struct KDCDHKeyInfo_Win2k {
  int nonce;
  heim_bit_string subjectPublicKey;
} KDCDHKeyInfo_Win2k;

ASN1EXP int    ASN1CALL decode_KDCDHKeyInfo_Win2k(const unsigned char *, size_t, KDCDHKeyInfo_Win2k *, size_t *);
ASN1EXP int    ASN1CALL encode_KDCDHKeyInfo_Win2k(unsigned char *, size_t, const KDCDHKeyInfo_Win2k *, size_t *);
ASN1EXP size_t ASN1CALL length_KDCDHKeyInfo_Win2k(const KDCDHKeyInfo_Win2k *);
ASN1EXP int    ASN1CALL copy_KDCDHKeyInfo_Win2k  (const KDCDHKeyInfo_Win2k *, KDCDHKeyInfo_Win2k *);
ASN1EXP void   ASN1CALL free_KDCDHKeyInfo_Win2k  (KDCDHKeyInfo_Win2k *);


/*
ReplyKeyPack-Win2k ::= SEQUENCE {
  replyKey        [0] EncryptionKey,
  nonce           [1] INTEGER (-2147483648..2147483647),
  ...,
}
*/

typedef struct ReplyKeyPack_Win2k {
  EncryptionKey replyKey;
  int nonce;
} ReplyKeyPack_Win2k;

ASN1EXP int    ASN1CALL decode_ReplyKeyPack_Win2k(const unsigned char *, size_t, ReplyKeyPack_Win2k *, size_t *);
ASN1EXP int    ASN1CALL encode_ReplyKeyPack_Win2k(unsigned char *, size_t, const ReplyKeyPack_Win2k *, size_t *);
ASN1EXP size_t ASN1CALL length_ReplyKeyPack_Win2k(const ReplyKeyPack_Win2k *);
ASN1EXP int    ASN1CALL copy_ReplyKeyPack_Win2k  (const ReplyKeyPack_Win2k *, ReplyKeyPack_Win2k *);
ASN1EXP void   ASN1CALL free_ReplyKeyPack_Win2k  (ReplyKeyPack_Win2k *);


/*
PA-PK-AS-REP-BTMM ::= SEQUENCE {
  dhSignedData    [0] heim_any OPTIONAL,
  encKeyPack      [1] heim_any OPTIONAL,
}
*/

typedef struct PA_PK_AS_REP_BTMM {
  heim_any *dhSignedData;
  heim_any *encKeyPack;
} PA_PK_AS_REP_BTMM;

ASN1EXP int    ASN1CALL decode_PA_PK_AS_REP_BTMM(const unsigned char *, size_t, PA_PK_AS_REP_BTMM *, size_t *);
ASN1EXP int    ASN1CALL encode_PA_PK_AS_REP_BTMM(unsigned char *, size_t, const PA_PK_AS_REP_BTMM *, size_t *);
ASN1EXP size_t ASN1CALL length_PA_PK_AS_REP_BTMM(const PA_PK_AS_REP_BTMM *);
ASN1EXP int    ASN1CALL copy_PA_PK_AS_REP_BTMM  (const PA_PK_AS_REP_BTMM *, PA_PK_AS_REP_BTMM *);
ASN1EXP void   ASN1CALL free_PA_PK_AS_REP_BTMM  (PA_PK_AS_REP_BTMM *);


/*
PkinitSP80056AOtherInfo ::= SEQUENCE {
  algorithmID     AlgorithmIdentifier,
  partyUInfo      [0] OCTET STRING,
  partyVInfo      [1] OCTET STRING,
  suppPubInfo     [2] OCTET STRING OPTIONAL,
  suppPrivInfo    [3] OCTET STRING OPTIONAL,
}
*/

typedef struct PkinitSP80056AOtherInfo {
  AlgorithmIdentifier algorithmID;
  heim_octet_string partyUInfo;
  heim_octet_string partyVInfo;
  heim_octet_string *suppPubInfo;
  heim_octet_string *suppPrivInfo;
} PkinitSP80056AOtherInfo;

ASN1EXP int    ASN1CALL decode_PkinitSP80056AOtherInfo(const unsigned char *, size_t, PkinitSP80056AOtherInfo *, size_t *);
ASN1EXP int    ASN1CALL encode_PkinitSP80056AOtherInfo(unsigned char *, size_t, const PkinitSP80056AOtherInfo *, size_t *);
ASN1EXP size_t ASN1CALL length_PkinitSP80056AOtherInfo(const PkinitSP80056AOtherInfo *);
ASN1EXP int    ASN1CALL copy_PkinitSP80056AOtherInfo  (const PkinitSP80056AOtherInfo *, PkinitSP80056AOtherInfo *);
ASN1EXP void   ASN1CALL free_PkinitSP80056AOtherInfo  (PkinitSP80056AOtherInfo *);


/*
PkinitSuppPubInfo ::= SEQUENCE {
  enctype         [0] INTEGER (-2147483648..2147483647),
  as-REQ          [1] OCTET STRING,
  pk-as-rep       [2] OCTET STRING,
  ticket          [3] Ticket,
  ...,
}
*/

typedef struct PkinitSuppPubInfo {
  int enctype;
  heim_octet_string as_REQ;
  heim_octet_string pk_as_rep;
  Ticket ticket;
} PkinitSuppPubInfo;

ASN1EXP int    ASN1CALL decode_PkinitSuppPubInfo(const unsigned char *, size_t, PkinitSuppPubInfo *, size_t *);
ASN1EXP int    ASN1CALL encode_PkinitSuppPubInfo(unsigned char *, size_t, const PkinitSuppPubInfo *, size_t *);
ASN1EXP size_t ASN1CALL length_PkinitSuppPubInfo(const PkinitSuppPubInfo *);
ASN1EXP int    ASN1CALL copy_PkinitSuppPubInfo  (const PkinitSuppPubInfo *, PkinitSuppPubInfo *);
ASN1EXP void   ASN1CALL free_PkinitSuppPubInfo  (PkinitSuppPubInfo *);


#endif /* __pkinit_asn1_h__ */
