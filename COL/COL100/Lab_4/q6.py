def lcs(s1, s2):
    if len(s1) == 0 or len(s2) == 0:
        return ""
    elif s1[0] == s2[0]:
        return (s1[0]+lcs(s1[1::], s2[1::]))
    else:
        return max(lcs(s1[1::], s2), lcs(s1, s2[1::]), lcs(s1[1::], s2[1::]))

print(lcs("sgahhscsdas", "hgdssahvcsdba"))
# sahcsda
# gahcsda