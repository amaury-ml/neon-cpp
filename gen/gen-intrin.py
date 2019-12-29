


i8 = ["s8", "u8"]
i16 = ["s16", "u16"]
i32 = ["s32", "u32"]
all_sint = ["s8", "s16", "s32"]
all_uint = ["u8", "u16", "u32"]
all_int = all_sint + all_uint
f16 = ["f16"]
f32 = ["f32"]
f64 = ["f64"]
all_floats = f16 + f32 + f64
all_vtypes = all_int + all_floats

simd = {
    "s8":  "int8_t",    "u8":  "uint8_t", 
    "s16": "int16_t",   "u16": "uint16_t", 
    "s32": "int32_t",   "u32": "uint32_t", 
    "s64": "int64_t",   "u64": "uint64_t",
    "f16": "float16_t", "f32": "float",     "f64": "double"
}

mask_type = {
    "s8":  "uint8_t",    "u8":  "uint8_t", 
    "s16": "uint16_t",   "u16": "uint16_t", 
    "s32": "uint32_t",   "u32": "uint32_t", 
    "f16": "uint16_t",   "f32": "uint32_t",     "f64": "uint64_t"
}

base_neon_type = "SIMD{simd}<{base_type}>::type"
base_template = """template <>
SIMD{simd}<{base_type}>::type {cppname}<{base_type}, {simd}>({arg_list}) {{
    return {intrin}{q}_{alter}({arg_forward});
}}
"""

compare_template = """template <>
SIMD{simd}<mask_type<{base_type}>::type>::type {cppname}<{base_type}, {simd}>({arg_list}) {{
    return {intrin}{q}_{alter}({arg_forward});
}}
"""

compare_template_d = """template <>
mask_type<{base_type}>::type {cppname}<{base_type}>({arg_list_d}) {{
    return {intrin}{q}_{alter}({arg_forward});
}}
"""

intrinsics = [
    ([64, 128], "vabd", "vabd", all_vtypes, base_template, 2),
    ([64, 128], "vabs", "vabs", all_sint + all_floats, base_template, 1),
    ([64, 128], "vadd", "vadd", all_vtypes, base_template, 2),
    # Special case 3 agrs, 1st one is the unsigned form of the base_type ("vbsl", all_vtypes, base_template, 3),
    ([64, 128], "vcage", "vcage", all_floats, compare_template, 2),
    #vcaged // single double
    #vcages // single float
    ([64, 128], "vcagt", "vcagt", all_floats, compare_template, 2),
    #vcagtd // single double
    #vcagts // single float
    ([64, 128], "vcale", "vcale", all_floats, compare_template, 2),
    # vcaled // single double
    # vcales // single float
    ([64, 128], "vcalt", "vcalt", all_floats, compare_template, 2),
    # vcaltd // single double
    # vcalts // single float
    ([64, 128], "vceq",   "vceq", all_vtypes, compare_template, 2),
    ([64],      "vceqd",  "vceq", ["u64", "s64", "f64"], compare_template_d, 2),
    ([32],      "vceqs",  "vceq", ["f32"], compare_template_d, 2),
    ([64, 128], "vceqz",  "vceqz", all_vtypes, compare_template, 1),
    ([64],      "vceqzd", "vceqz", ["u64", "s64", "f64"], compare_template_d, 1),
    ([32],      "vceqzs", "vceqz", ["f32"], compare_template_d, 1),
    ([64, 128], "vcge",   "vcge", all_vtypes, compare_template, 2),
    ([64],      "vcged",  "vcge", ["u64", "s64", "f64"], compare_template_d, 2),
    ([32],      "vcges",  "vcge", ["f32"], compare_template_d, 2),
    ([64, 128], "vcgez",  "vcgez", all_sint + all_floats, compare_template, 1),
    ([64],      "vcgezd", "vcgez", ["s64", "f64"], compare_template_d, 1),
    ([32],      "vcgezs", "vcgez", ["f32"], compare_template_d, 1),
    ([64, 128], "vcgt",   "vcgt", all_vtypes, compare_template, 2),
    ([64],      "vcgtd",  "vcgt", ["u64", "s64", "f64"], compare_template_d, 2),
    ([32],      "vcgts",  "vcgt", ["f32"], compare_template_d, 2),
    ([64, 128], "vcgtz",  "vcgtz", all_sint + all_floats, compare_template, 1),
    ([64],      "vcgtzd", "vcgtz", ["s64", "f64"], compare_template_d, 1),
    ([32],      "vcgtzs", "vcgtz", ["f32"], compare_template_d, 1),
    ([64, 128], "vcle",   "vcle", all_vtypes, compare_template, 2),
    ([64],      "vcled",  "vcle", ["u64", "s64", "f64"], compare_template_d, 2),
    ([32],      "vcles",  "vcle", ["f32"], compare_template_d, 2),
    ([64, 128], "vclez",  "vclez", all_sint + all_floats, compare_template, 1),
    ([64],      "vclezd", "vclez", ["s64", "f64"], compare_template_d, 1),
    ([32],      "vclezs", "vclez", ["f32"], compare_template_d, 1),
    ([64, 128], "vclt",   "vclt", all_vtypes, compare_template, 2),
    ([64],      "vcltd",  "vclt", ["u64", "s64", "f64"], compare_template_d, 2),
    ([32],      "vclts",  "vclt", ["f32"], compare_template_d, 2),
    ([64, 128], "vcltz",  "vcltz", all_sint + all_floats, compare_template, 1),
    ([64],      "vcltzd", "vcltz", ["s64", "f64"], compare_template_d, 1),
    ([32],      "vcltzs", "vcltz", ["f32"], compare_template_d, 1),
    #vcombine
    #vcopy
    #vcvt
    ([64, 128], "vdiv",   "vdiv", all_floats, base_template, 2),
    #vdup[hbsd]{,q}_lane{,q}
    ([64, 128], "vdup",   "vdup", all_vtypes, """template <>
SIMD{simd}<{base_type}>::type vdup<{base_type}, {simd}>({base_type} v) {{
    return vdup{q}_n_{alter}(v);
}}
"""     , 1),
    #vext
    ([64, 128], "vfma",   "vfma", all_floats, base_template, 3),
    #vfma[hbsd]{,q}_lane{,q}
    ([128], "vfma",   "vfma", all_floats, """template <>
SIMD{simd}<{base_type}>::type vfma<{base_type}, {simd}>({arg_list}, {base_type} v2) {{
    return vfma{q}_n_{alter}({arg_forward}, v2);
}}
"""     , 2),
    ([64], "vfma",   "vfma", ["f16", "f32"], """template <>
SIMD{simd}<{base_type}>::type vfma<{base_type}, {simd}>({arg_list}, {base_type} v2) {{
    return vfma{q}_n_{alter}({arg_forward}, v2);
}}
"""     , 2),

    ([64, 128], "vfms",   "vfms", all_floats, base_template, 3),
    #vfms[hbsd]{,q}_lane{,q}
    ([128], "vfms",   "vfms", all_floats, """template <>
SIMD{simd}<{base_type}>::type vfms<{base_type}, {simd}>({arg_list}, {base_type} v2) {{
    return vfms{q}_n_{alter}({arg_forward}, v2);
}}
"""     , 2),
    ([64], "vfms",   "vfms", ["f16", "f32"], """template <>
SIMD{simd}<{base_type}>::type vfms<{base_type}, {simd}>({arg_list}, {base_type} v2) {{
    return vfms{q}_n_{alter}({arg_forward}, v2);
}}
"""     , 2),

]


print "namespace neon {"
for simds, intrinsic, cppname, alternatives, template, nargs in intrinsics:
    for alternative in alternatives:
        if alternative == "f16": continue
        #print intrinsic,  alternative, simd[alternative], template
        base_type = simd[alternative]
        #print map(lambda a: (base_neon_type + " const& v" + str(a)).format(base_type = base_type), range(0, nargs))
        for s in simds:
            print template.format(
                simd = str(s), 
                q = "q" if s == 128 else "",
                base_type = base_type, 
                intrin = intrinsic, 
                cppname = cppname,
                alter = alternative,
                arg_list = ", ".join(map(lambda a: (base_neon_type + " const& v" + str(a)).format(simd = s, base_type = base_type), range(0, nargs))),
                arg_list_d = ", ".join(map(lambda a: (base_type + " const& v" + str(a)).format(simd = s, base_type = base_type), range(0, nargs))),
                arg_forward = ", ".join(map(lambda a: "v" + str(a), range(0, nargs))),
                
                )
print "} // namespace neon"
