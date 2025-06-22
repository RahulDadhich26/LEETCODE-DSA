class Solution {
public:
string validIPAddress(string queryIP) {
   if (isValidIPv4(queryIP)) {
       return "IPv4";
   } else if (isValidIPv6(queryIP)) {
       return "IPv6";
   } else {
       return "Neither";
   }
}

bool isValidIPv4(string ip) {
   if (ip.empty() || ip.back() == '.') return false;
   
   int count = 0;
   stringstream ss(ip);
   string part;
   
   while (getline(ss, part, '.')) {
       count++;
       if (count > 4) return false;
       
       if (!isValidIPv4Part(part)) {
           return false;
       }
   }
   
   return count == 4;
}

bool isValidIPv4Part(string part) {
   if (part.empty() || part.length() > 3) return false;
   
   if (part.length() > 1 && part[0] == '0') return false;
   
   for (char c : part) {
       if (!isdigit(c)) return false;
   }
   
   int num = stoi(part);
   return num >= 0 && num <= 255;
}

bool isValidIPv6(string ip) {
   if (ip.empty() || ip.back() == ':') return false;
   
   int count = 0;
   stringstream ss(ip);
   string part;
   
   while (getline(ss, part, ':')) {
       count++;
       if (count > 8) return false;
       
       if (!isValidIPv6Part(part)) {
           return false;
       }
   }
   
   return count == 8;
}

bool isValidIPv6Part(string part) {
   if (part.empty() || part.length() > 4) return false;
   
   for (char c : part) {
       if (!isxdigit(c)) return false;
   }
   
   return true;
}
};