//
// Created by sine on 19-1-15.
//

#ifndef SWEETPOTATO_SIP_HEADER_H
#define SWEETPOTATO_SIP_HEADER_H
/**
 * RFC3261 SIP: Session Initiation Protocol. J. Rosenberg, H. Schulzrinne, G.
     Camarillo, A. Johnston, J. Peterson, R. Sparks, M. Handley, E.
     Schooler. June 2002. (Format: TXT=647976 bytes) (Obsoletes RFC2543)
     (Updated by RFC3265, RFC3853, RFC4320, RFC4916, RFC5393, RFC5621,
     RFC5626, RFC5630, RFC5922, RFC5954, RFC6026, RFC6141, RFC6665,
     RFC6878, RFC7462, RFC7463, RFC8217) (Status: PROPOSED STANDARD)
     (DOI: 10.17487/RFC3261)
 */
//https://www.ietf.org/
// http://www.cs.columbia.edu/sip/compact.html
/**
Abbreviation	Header	defined by	origin (mnemonic)
a	Accept-Contact	draft-ietf-sip-callerprefs	--
b	Referred-By	-refer-	"by"
c	Content-Type	RFC 3261
e	Content-Encoding	RFC 3261
f	From	RFC 3261
i	Call-ID	RFC 3261
k	Supported	RFC 3261	"know"
l	Content-Length	RFC 3261
m	Contact	RFC 3261	"moved"
o	Event	-event-	"occurance"
r	Refer-To	-refer-
s	Subject	RFC 3261
t	To	RFC 3261
u	Allow-Events	-events-	"understand"
v	Via	RFC 3261
 */
typedef enum sip_header_type_e {
    sip_type_Accept,
    sip_type_Accept_Contact,
    sip_type_Accept_Encoding,
    sip_type_Accept_Language,
    sip_type_Accept_Resource_Priority,
    sip_type_Alert_Info,
    sip_type_Allow,
    sip_type_Allow_Events,
    sip_type_Answer_Mode,
    sip_type_Authentication_Info,
    sip_type_Authorization,
    sip_type_Call_ID,
    sip_type_Call_Info,
    sip_type_Cellular_Network_Info,
    sip_type_Contact,
    sip_type_Content_Disposition,
    sip_type_Content_Encoding,
    sip_type_Content_ID,
    sip_type_Content_Language,
    sip_type_Content_Length,
    sip_type_Content_Type,
    sip_type_CSeq,
    sip_type_Date,
    sip_type_Encryption,//Deprecated
    //sip_type_Dummy,
    sip_type_Error_Info,
    sip_type_Event,
    sip_type_Expires,
    sip_type_Feature_Caps,
    sip_type_Flow_Timer,
    sip_type_From,
    sip_type_Geolocation,
    sip_type_Geolocation_Error,
    sip_type_Geolocation_Routing,
    sip_type_Hide,//Deprecated
    sip_type_History_Info,
    sip_type_Identity,
    sip_type_Identity_Info,//Deprecated
    sip_type_Info_Package,
    sip_type_In_Reply_To,
    sip_type_Join,
    sip_type_Max_Breadth,//
    sip_type_Max_Forwards,
    sip_type_MIME_Version,
    sip_type_Min_Expires,
    sip_type_Min_SE,
    sip_type_Organization,
    sip_type_Path,
    sip_type_Permission_Missing,//
    sip_type_Policy_Contact,//
    sip_type_Policy_ID,//
    sip_type_Priv_Answer_Mode,//
    sip_type_Priority,
    sip_type_Privacy,
    sip_type_Proxy_Authenticate,
    sip_type_Proxy_Authorization,
    sip_type_Proxy_Require,
    sip_type_RAck,
    sip_type_Reason,
    sip_type_Record_Route,
    sip_type_Reason_Phrase,//
    sip_type_Recv_Info,//
    sip_type_Refer_Events_At,//
    sip_type_Refer_Sub,
    sip_type_Refer_To,
    sip_type_Referred_By,
    sip_type_Reject_Contact,
    sip_type_Relayed_Charge,//
    sip_type_Replaces,
    sip_type_Reply_To,
    sip_type_Request_Disposition,
    sip_type_Require,
    sip_type_Resource_Priority,
    sip_type_Resource_Share,//
    sip_type_Response_Key,//Deprecated
    sip_type_Restoraion_Info,//
    sip_type_Retry_After,
    sip_type_Route,
    sip_type_RSeq,
    sip_type_Security_Client,
    sip_type_Security_Server,
    sip_type_Security_Verify,
    sip_type_Server,
    sip_type_Service_Route,
    sip_type_Session_Expires,
    sip_type_Session_ID,//
    sip_type_SIP_ETag,
    sip_type_SIP_If_Match,
    sip_type_Subject,
    sip_type_Subscription_State,
    sip_type_Supported,
    sip_type_Suppress_If_Match,//
    sip_type_Target_Dialog,
    sip_type_Timestamp,
    sip_type_To,
    sip_type_Unsupported,
    sip_type_Trigger_Consent,//
    sip_type_User_Agent,
    sip_type_User_to_User,//
    sip_type_Via,
    sip_type_Warning,
    sip_type_WWW_Authenticate,

    sip_type_P_Access_Network_Info,
    sip_type_P_Answer_State,
    sip_type_P_Asserted_Identity,
    sip_type_P_Asserted_Service,//
    sip_type_P_Associated_URI,
    sip_type_P_Called_Party_ID,
    sip_type_P_Charging_Function_Addresses,
    sip_type_P_Charging_Vector,
    sip_type_P_DCS_Billing_Info,
    sip_type_P_DCS_LAES,
    sip_type_P_DCS_OSPS,
    sip_type_P_DCS_Redirect,
    sip_type_P_DCS_Trace_Party_ID,
    sip_type_P_Early_Media,
    sip_type_P_Media_Authorization,
    sip_type_P_Preferred_Identity,
    sip_type_P_Preferred_Service,//
    sip_type_P_private_Network_Indication,//
    sip_type_P_Profile_Key,
    sip_type_P_Refused_URI_List,//
    sip_type_P_User_Database,
    sip_type_P_Visited_Network_ID
}sip_header_type;

const char *sip_header_get_name(sip_header_type type)
{
    switch (type){
        case sip_type_Accept:
            return "Accept";
        case sip_type_Accept_Contact:
            return "Accept-Contact";
        case sip_type_Accept_Encoding:
            return "Accept-Encoding";
        case sip_type_Accept_Language:
            return "Accept-Language";
        case sip_type_Accept_Resource_Priority:
            return "Accept-Resource-Priority";
        case sip_type_Alert_Info:
            return "Alert-Info";
        case sip_type_Allow:
            return "Allow";
        case sip_type_Allow_Events:
            return "Allow-Events";
        case sip_type_Answer_Mode:
            return "Answer-Mode";
        case sip_type_Authentication_Info:
            return "Authentication-Info";
        case sip_type_Authorization:
            return "Authorization";
        case sip_type_Call_ID:
            return "Accept";
        case sip_type_Call_Info:
            return "Call-Info";
        case sip_type_Cellular_Network_Info:
            return "Accept";
        case sip_type_Contact:
            return "Contact";
        case sip_type_Content_Disposition:
            return "Content-Disposition";
        case sip_type_Content_Encoding:
            return "Content-Encoding";
        case sip_type_Content_ID:
            return "Content-ID";
        case sip_type_Content_Language:
            return "Content-Language";
        case sip_type_Content_Length:
            return "Content-Language";
        case sip_type_Content_Type:
            return "Content-Type";
        case sip_type_CSeq:
            return "CSeq";
        case sip_type_Date:
            return "Date";
        //Deprecated:已经丢弃
        //case sip_type_Encryption:
        //    return "Encryption";
        //case sip_type_Dummy:
        //    return "Dummy";
        case sip_type_Error_Info:
            return "Error-Info";
        case sip_type_Event:
            return "Event";
        case sip_type_Expires:
            return "Expires";
        case sip_type_Feature_Caps:
            return "Feature-Caps";
        case sip_type_Flow_Timer:
            return "Flow-Timer";
        case sip_type_From:
            return "From";
        case sip_type_Geolocation:
            return "Geolocation";
        case sip_type_Geolocation_Error:
            return "Accept";
        case sip_type_Geolocation_Routing:
            return "Geolocation-Error";
        //Deprecated:已经丢弃
        //case sip_type_Hide:
        //    return "Hide";
        case sip_type_History_Info:
            return "History-Info";
        case sip_type_Identity:
            return "Identity";
        //Deprecated:已经丢弃
        //case sip_type_Identity_Info:
        //    return "Identity_Info";
        case sip_type_Info_Package:
            return "Info-Package";
        case sip_type_In_Reply_To:
            return "In-Reply-To";
        case sip_type_Join:
            return "Join";
        case sip_type_Max_Breadth:
            return "Max-Breadth";
        case sip_type_MIME_Version:
            return "MIME_Version";
        case sip_type_Min-Expires:
            return "Min-Expires";
        case sip_type_Min_SE:
            return "Min-SE";
        case sip_type_Organization:
            return "Organization";
        case sip_type_Path:
            return "Path";
        case sip_type_Permission_Missing:
            return "Permission-Missing";
        case sip_type_Policy_Contact:
            return "Policy-Contact";
        case sip_type_Policy_ID:
            return "Policy-ID";
        case sip_type_Priv_Answer_Mode:
            return "Priv-Answer-Mode";
        case sip_type_Priority:
            return "Priority";
        case sip_type_Privacy:
            return "Privacy";
        case sip_type_Proxy_Authenticate:
            return "Proxy-Authenticate";
        case sip_type_Proxy_Authorization:
            return "Proxy-Authorization";
        case sip_type_Proxy_Require:
            return "Proxy-Require";
        case sip_type_RAck:
            return "RAck";
        case sip_type_Reason:
            return "Reason";
        case sip_type_Record_Route:
            return "Record-Route";
        case sip_type_Reason_Phrase:
            return "Reason-Phrase";
        case sip_type_Recv_Info:
            return "Recv-Info";
        case sip_type_Refer_Events_At:
            return "Refer-Events-At";
        case sip_type_Refer_Sub:
            return "Refer-Sub";
        case sip_type_Refer_To:
            return "Refer-To";
        case sip_type_Referred_By:
            return "Referred-By";
        case sip_type_Reject_Contact:
            return "Reject-Contact";
        case sip_type_Relayed_Charge:
            return "Relayed-Charge";
        case sip_type_Replaces:
            return "Replaces";
        case sip_type_Reply_To:
            return "Reply-To";
        case sip_type_Request_Disposition:
            return "Request-Disposition";
        case sip_type_Require:
            return "Require";
        case sip_type_Resource_Priority:
            return "Resource-Priority";
        case sip_type_Resource_Share:
            return "Resource-Share";
        //Deprecated:已经丢弃
        //case sip_type_Response_Key:
        //    return "Response-Key";
        case sip_type_Restoraion_Info:
            return "Restoraion-Info";
        case sip_type_Retry_After:
            return "Retry-After";
        case sip_type_Route:
            return "Route";
        case sip_type_RSeq:
            return "RSeq";
        case sip_type_Security_Client:
            return "Security-Client";
        case sip_type_Security_Server:
            return "Security-Server";
        case sip_type_Security_Verify:
            return "Security-Verify";
        case sip_type_Server:
            return "Server";
        case sip_type_Service_Route:
            return "Service-Route";
        case sip_type_Session_Expires:
            return "Session-Expires";
        case sip_type_Session_ID:
            return "Session-ID";
        case sip_type_SIP_ETag:
            return "SIP-ETag";
        case sip_type_SIP_If_Match:
            return "SIP-If-Match";
        case sip_type_Subject:
            return "Subject";
        case sip_type_Subscription_State:
            return "Subscription-State";
        case sip_type_Supported:
            return "Supported";
        case sip_type_Suppress_If_Match:
            return "Suppress-If-Match";
        case sip_type_Target_Dialog:
            return "Target-Dialog";
        case sip_type_Timestamp:
            return "Timestamp";
        case sip_type_To:
            return "To";
        case sip_type_Unsupported:
            return "Unsupported";
        case sip_type_Trigger_Consent:
            return "Trigger-Consent";
        case sip_type_User_Agent:
            return "User-Agent";
        case sip_type_User_to_User:
            return "User-to-User";
        case sip_type_Via:
            return "Via";
        case sip_type_Warning:
            return "Warning";
        case sip_type_WWW_Authenticate:
            return "WWW-Authenticate";
        case sip_type_P_Access_Network_Info:
            return "P-Access-Network-Info";
        case sip_type_P_Answer_State:
            return "P-Answer-State";
        case sip_type_P_Asserted_Identity:
            return "P-Asserted-Identity";
        case sip_type_P_Asserted_Service:
            return "P-Asserted-Service";
        case sip_type_P_Associated_URI:
            return "P-Associated-URI";
        case sip_type_P_Called_Party_ID:
            return "P-Called-Party-ID";
        case sip_type_P_Charging_Function_Addresses:
            return "P-Charging-Function-Addresses";
        case sip_type_P_Charging_Vector:
            return "P-Charging-Vector";
        case sip_type_P_DCS_Billing_Info:
            return "P-DCS-Billing-Info";
        case sip_type_P_DCS_LAES:
            return "P-DCS-LAES";
        case sip_type_P_DCS_OSPS:
            return "P-DCS-OSPS";
        case sip_type_P_DCS_Redirect:
            return "P-DCS-Redirect";
        case sip_type_P_DCS_Trace_Party_ID:
            return "P-DCS-Trace-Party-ID";
        case sip_type_P_Early_Media:
            return "P-Early-Media";
        case sip_type_P_Media_Authorization:
            return "P-Media-Authorization";
        case sip_type_P_Preferred_Identity:
            return "P-Preferred-Identity";
        case sip_type_P_Preferred_Service:
            return "P-Preferred-Service";
        case sip_type_P_private_Network_Indication:
            return "P-private-Network-Indication";
        case sip_type_P_Profile_Key:
            return "P-Profile-Key";
        case sip_type_P_Refused_URI_List:
            return "P-Refused-URI-List";
        case sip_type_P_User_Database:
            return "P-User-Database";
        case sip_type_P_Visited_Network_ID:
            return "P-Visited-Network-ID";

    }
}
#endif //SWEETPOTATO_SIP_HEADER_H
