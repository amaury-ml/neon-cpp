


i8 = ["s8", "u8"]
i16 = ["s16", "u16"]
i32 = ["s32", "u32"]
all_sint_no64 = ["s8", "s16", "s32"]
all_uint_no64 = ["u8", "u16", "u32"]
all_sint = all_sint_no64 + ["s64"]
all_uint = all_uint_no64 + ["u64"]
all_int_no64 = all_sint_no64 + all_uint_no64
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

base_neon_type = "SIMD{simd}<{base_type}>"
base_template = """template <> __attribute__((always_inline))
SIMD{simd}<{base_type}> {cppname}<{base_type}, {simd}>({arg_list}) {{
    return {intrin}{q}_{alter}({arg_forward});
}}
"""

compare_template = """template <> __attribute__((always_inline))
SIMD{simd}<mask_type<{base_type}>::type> {cppname}<{base_type}, {simd}>({arg_list}) {{
    return {intrin}{q}_{alter}({arg_forward});
}}
"""

compare_template_d = """template <> __attribute__((always_inline))
mask_type<{base_type}>::type {cppname}<{base_type}>({arg_list_d}) {{
    return {intrin}{q}_{alter}({arg_forward});
}}
"""

intrinsics = [
    ([64, 128], "vabd", "vabd", all_int_no64 + all_floats, base_template, 2),
    ([64, 128], "vabs", "vabs", all_sint + all_floats, base_template, 1),
    ([64, 128], "vadd", "vadd", all_vtypes, """template <> __attribute__((always_inline))
SIMD{simd}<{base_type}> {cppname}<{base_type}, {simd}>(SIMD{simd}<{base_type}> const& v0, SIMD{simd}<{base_type}> const& v1) {{
    return {intrin}{q}_{alter}({arg_forward});
}}""" , 2),
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
    ([64, 128], "vdup",   "vdup", all_vtypes, """template <> __attribute__((always_inline))
SIMD{simd}<{base_type}> vdup<{base_type}, {simd}>({base_type} v) {{
    return vdup{q}_n_{alter}(v);
}}
"""     , 1),
    #vext
    ([64, 128], "vfma",   "vfma", all_floats, base_template, 3),
    #vfma[hbsd]{,q}_lane{,q}
    ([128], "vfma",   "vfma", all_floats, """template <> __attribute__((always_inline))
SIMD{simd}<{base_type}> vfma<{base_type}, {simd}>({arg_list}, {base_type} v2) {{
    return vfma{q}_n_{alter}({arg_forward}, v2);
}}
"""     , 2),
    ([64], "vfma",   "vfma", ["f16", "f32"], """template <> __attribute__((always_inline))
SIMD{simd}<{base_type}> vfma<{base_type}, {simd}>({arg_list}, {base_type} v2) {{
    return vfma{q}_n_{alter}({arg_forward}, v2);
}}
"""     , 2),

    ([64, 128], "vfms",   "vfms", all_floats, base_template, 3),
    #vfms[hbsd]{,q}_lane{,q}
    ([128], "vfms",   "vfms", all_floats, """template <> __attribute__((always_inline))
SIMD{simd}<{base_type}> vfms<{base_type}, {simd}>({arg_list}, {base_type} v2) {{
    return vfms{q}_n_{alter}({arg_forward}, v2);
}}
"""     , 2),
    ([64], "vfms",   "vfms", ["f16", "f32"], """template <> __attribute__((always_inline))
SIMD{simd}<{base_type}> vfms<{base_type}, {simd}>({arg_list}, {base_type} v2) {{
    return vfms{q}_n_{alter}({arg_forward}, v2);
}}
"""     , 2),

    ([128], "vget_high",   "vget_high", all_vtypes, """template <> __attribute__((always_inline))
SIMD64<{base_type}> vget_high<{base_type}>(SIMD128<{base_type}> const& v) {{
    return vget_high_{alter}(v);
}}
"""     , 1),

    ([128], "vget_low",   "vget_low", all_vtypes, """template <> __attribute__((always_inline))
SIMD64<{base_type}> vget_low<{base_type}>(SIMD128<{base_type}> const& v) {{
    return vget_low_{alter}(v);
}}
"""     , 1),
    #vget_lane
    ([64, 128], "vhadd",   "vhadd", all_int_no64, base_template, 2),
    ([64, 128], "vhsub",   "vhsub", all_int_no64, base_template, 2),
    ([64, 128], "vld1",   "vld1", all_vtypes, """template <> __attribute__((always_inline))
SIMD{simd}<{base_type}> vld1<SIMD{simd}<{base_type}>>({base_type} const* m) {{
    return vld1{q}_{alter}(m);
}}"""   , 1),
    ([64, 128], "vld1_dup",   "vld1_dup", all_vtypes, """template <> __attribute__((always_inline))
SIMD{simd}<{base_type}> vld1_dup<SIMD{simd}<{base_type}>>({base_type} const* m) {{
    return vld1{q}_{alter}(m);
}}"""   , 1),
    #vld1_lane
    ([64, 128], "vld1_x2",   "vld1_x2", all_vtypes, """template <> __attribute__((always_inline))
std::array<SIMD{simd}<{base_type}>, 2> vld1_x2<SIMD{simd}<{base_type}>>({base_type} const* m) {{
    auto v = vld1{q}_{alter}_x2(m);
    return {{v.val[0], v.val[1]}};
}}"""   , 1),

    ([64, 128], "vld1_x3",   "vld1_x3", all_vtypes, """template <> __attribute__((always_inline))
std::array<SIMD{simd}<{base_type}>, 3> vld1_x3<SIMD{simd}<{base_type}>>({base_type} const* m) {{
    auto v = vld1{q}_{alter}_x3(m);
    return {{v.val[0], v.val[1], v.val[2]}};
}}"""   , 1),

    ([64, 128], "vld1_x4",   "vld1_x4", all_vtypes, """template <> __attribute__((always_inline))
std::array<SIMD{simd}<{base_type}>, 4> vld1_x4<SIMD{simd}<{base_type}>>({base_type} const* m) {{
    auto v = vld1{q}_{alter}_x4(m);
    return {{v.val[0], v.val[1], v.val[2], v.val[3]}};
}}"""   , 1),


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
