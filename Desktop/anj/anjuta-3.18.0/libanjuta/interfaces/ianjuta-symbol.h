/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-symbol.h -- Autogenerated from libanjuta.idl
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef _IANJUTA_SYMBOL_H_
#define _IANJUTA_SYMBOL_H_

#include <glib-object.h>
#include <gdk/gdk.h>
#include <gio/gio.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_SYMBOL (ianjuta_symbol_get_type ())
#define IANJUTA_SYMBOL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_SYMBOL, IAnjutaSymbol))
#define IANJUTA_IS_SYMBOL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_SYMBOL))
#define IANJUTA_SYMBOL_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_SYMBOL, IAnjutaSymbolIface))

#define IANJUTA_TYPE_SYMBOL_FIELD (ianjuta_symbol_field_get_type())
#define IANJUTA_TYPE_SYMBOL_TYPE (ianjuta_symbol_type_get_type())

#define IANJUTA_SYMBOL_ERROR ianjuta_symbol_error_quark()

typedef struct _IAnjutaSymbol IAnjutaSymbol;
typedef struct _IAnjutaSymbolIface IAnjutaSymbolIface;

/**
 * IAnjutaSymbolField:
 * @IANJUTA_SYMBOL_FIELD_ID: Integer. A unique ID of the symbol
 * @IANJUTA_SYMBOL_FIELD_NAME: String. Name of the symbol
 * @IANJUTA_SYMBOL_FIELD_FILE_POS: Integer. The file line number where the symbol is found.
 * @IANJUTA_SYMBOL_FIELD_SCOPE_DEF_ID: Integer. A unique ID to define scope created by this symbol.
 * @IANJUTA_SYMBOL_FIELD_FILE_SCOPE: Boolean: TRUE if symbol is within file scope,
 *     otherwise FALSE.
 * @IANJUTA_SYMBOL_FIELD_SIGNATURE: String. Signature of a method, if symbol is a funtion.
 *     Namely, the arguments list of the funtion.
 * @IANJUTA_SYMBOL_FIELD_RETURNTYPE: String. Return type of a method, if symbol is a function.
 * @IANJUTA_SYMBOL_FIELD_FILE_PATH: String. The relative path to the file where the symbol is found.
 * @IANJUTA_SYMBOL_FIELD_PROJECT_NAME: String. The project name to which the symbol belongs to.
 * @IANJUTA_SYMBOL_FIELD_PROJECT_VERSION: String. The project version to which the symbol belongs to.
 * @IANJUTA_SYMBOL_FIELD_IMPLEMENTATION: String. Implementation attribute of a symbol. It may be
 *     "pure virtual", "virtual", etc.
 * @IANJUTA_SYMBOL_FIELD_ACCESS: String. Access attribute of a symbol.
 *     It may be "public", "private" etc.
 * @IANJUTA_SYMBOL_FIELD_KIND: Kind attribute of a symbol, such as
 *     "enumerator", "namespace", "class" etc.
 * @IANJUTA_SYMBOL_FIELD_TYPE: Both string and Integer. Type attribute of a symbol.
 *     In string form, it is name of the type in string form.
 *     In integer form, it is IAnjutaSymbolType enumerator value.
 * @IANJUTA_SYMBOL_FIELD_TYPE_NAME: type_name attribute of a symbol.
 *     If a type could be "class" then its type_name may be "MyFooClass" etc.
 * @IANJUTA_SYMBOL_FIELD_IS_CONTAINER: Boolean. TRUE if symbol is
 *     a scope container, such as namespace, class, struct etc., otherwise
 *     FALSE.
 * @IANJUTA_SYMBOL_FIELD_END: The end marker.
 *
 * Symbol Fields. Used to define and retrieve results from query. Each of
 * these fields are either integer or string. Use the right method to
 * retrieve them. That is, for integer use ianjuta_symbol_get_int(),
 * for string use ianjuta_symbol_get_string(), and for boolean use
 * ianjuta_symbol_get_boolean(). Some fields can be in both forms,
 * e.g. #IANJUTA_SYMBOL_FIELD_TYPE.
 */
typedef enum {
	IANJUTA_SYMBOL_FIELD_ID,
	IANJUTA_SYMBOL_FIELD_NAME,
	IANJUTA_SYMBOL_FIELD_FILE_POS,
	IANJUTA_SYMBOL_FILED_SCOPE_DEF_ID,
	IANJUTA_SYMBOL_FIELD_FILE_SCOPE,
	IANJUTA_SYMBOL_FIELD_SIGNATURE,
	IANJUTA_SYMBOL_FIELD_RETURNTYPE,
	IANJUTA_SYMBOL_FIELD_TYPE,
	IANJUTA_SYMBOL_FIELD_TYPE_NAME,
	IANJUTA_SYMBOL_FIELD_FILE_PATH,
	IANJUTA_SYMBOL_FIELD_PROJECT_NAME,
	IANJUTA_SYMBOL_FIELD_PROJECT_VERSION,
	IANJUTA_SYMBOL_FIELD_IMPLEMENTATION,
	IANJUTA_SYMBOL_FIELD_ACCESS,
	IANJUTA_SYMBOL_FIELD_KIND,
	IANJUTA_SYMBOL_FIELD_IS_CONTAINER,
	IANJUTA_SYMBOL_FIELD_END
} IAnjutaSymbolField;

/**
 * IAnjutaSymbolType:
 * @IANJUTA_SYMBOL_TYPE_NONE: None spedified.
 * @IANJUTA_SYMBOL_TYPE_UNDEF: Unknown type.
 * @IANJUTA_SYMBOL_TYPE_CLASS: Class declaration
 * @IANJUTA_SYMBOL_TYPE_ENUM: Enum declaration
 * @IANJUTA_SYMBOL_TYPE_ENUMERATOR: Enumerator value
 * @IANJUTA_SYMBOL_TYPE_FIELD: Field (Java only)
 * @IANJUTA_SYMBOL_TYPE_FUNCTION: Function definition
 * @IANJUTA_SYMBOL_TYPE_INTERFACE: Interface (Java only)
 * @IANJUTA_SYMBOL_TYPE_MEMBER: Member variable of class/struct
 * @IANJUTA_SYMBOL_TYPE_METHOD: Class method (Java only)
 * @IANJUTA_SYMBOL_TYPE_NAMESPACE: Namespace declaration
 * @IANJUTA_SYMBOL_TYPE_PACKAGE: Package (Java only)
 * @IANJUTA_SYMBOL_TYPE_PROTOTYPE: Function prototype
 * @IANJUTA_SYMBOL_TYPE_STRUCT: Struct declaration
 * @IANJUTA_SYMBOL_TYPE_TYPEDEF: Typedef
 * @IANJUTA_SYMBOL_TYPE_UNION: Union
 * @IANJUTA_SYMBOL_TYPE_VARIABLE: Variable
 * @IANJUTA_SYMBOL_TYPE_EXTERNVAR: Extern or forward declaration
 * @IANJUTA_SYMBOL_TYPE_MACRO: Macro (without arguments)
 * @IANJUTA_SYMBOL_TYPE_MACRO_WITH_ARG: Parameterized macro
 * @IANJUTA_SYMBOL_TYPE_FILE: File (Pseudo tag)
 * @IANJUTA_SYMBOL_TYPE_OTHER: Other (non C/C++/Java tag)
 * @IANJUTA_SYMBOL_TYPE_SCOPE_CONTAINER: types which are subjected to create a scope.
 * @IANJUTA_SYMBOL_TYPE_MAX: Maximum value, used as end marker.
 */
typedef enum {
	IANJUTA_SYMBOL_TYPE_NONE = 0,
	IANJUTA_SYMBOL_TYPE_UNDEF = 1,
	IANJUTA_SYMBOL_TYPE_CLASS = 2,
	IANJUTA_SYMBOL_TYPE_ENUM = 4,
	IANJUTA_SYMBOL_TYPE_ENUMERATOR = 8,
	IANJUTA_SYMBOL_TYPE_FIELD = 16,
	IANJUTA_SYMBOL_TYPE_FUNCTION = 32,
	IANJUTA_SYMBOL_TYPE_INTERFACE = 64,
	IANJUTA_SYMBOL_TYPE_MEMBER = 128,
	IANJUTA_SYMBOL_TYPE_METHOD = 256,
	IANJUTA_SYMBOL_TYPE_NAMESPACE = 512,
	IANJUTA_SYMBOL_TYPE_PACKAGE = 1024,
	IANJUTA_SYMBOL_TYPE_PROTOTYPE = 2048,
	IANJUTA_SYMBOL_TYPE_STRUCT = 4096,
	IANJUTA_SYMBOL_TYPE_TYPEDEF = 8192,
	IANJUTA_SYMBOL_TYPE_UNION = 16384,
	IANJUTA_SYMBOL_TYPE_VARIABLE = 32768,
	IANJUTA_SYMBOL_TYPE_EXTERNVAR = 65536,
	IANJUTA_SYMBOL_TYPE_MACRO = 131072,
	IANJUTA_SYMBOL_TYPE_MACRO_WITH_ARG = 262144,
	IANJUTA_SYMBOL_TYPE_FILE = 524288,
	IANJUTA_SYMBOL_TYPE_OTHER = 1048576,
	IANJUTA_SYMBOL_TYPE_SCOPE_CONTAINER = IANJUTA_SYMBOL_TYPE_CLASS | IANJUTA_SYMBOL_TYPE_ENUM | IANJUTA_SYMBOL_TYPE_INTERFACE | IANJUTA_SYMBOL_TYPE_NAMESPACE | IANJUTA_SYMBOL_TYPE_PACKAGE | IANJUTA_SYMBOL_TYPE_STRUCT | IANJUTA_SYMBOL_TYPE_UNION,
	IANJUTA_SYMBOL_TYPE_MAX = 2097151
} IAnjutaSymbolType;


struct _IAnjutaSymbolIface {
	GTypeInterface g_iface;
	

	gboolean (*get_boolean) (IAnjutaSymbol *obj, IAnjutaSymbolField field, GError **err);
	GFile* (*get_file) (IAnjutaSymbol *obj, GError **err);
	const GdkPixbuf * (*get_icon) (IAnjutaSymbol *obj, GError **err);
	gint (*get_int) (IAnjutaSymbol *obj, IAnjutaSymbolField field, GError **err);
	const gchar* (*get_string) (IAnjutaSymbol *obj, IAnjutaSymbolField field, GError **err);
	IAnjutaSymbolType (*get_sym_type) (IAnjutaSymbol *obj, GError **err);

};

GType ianjuta_symbol_field_get_type (void);
GType ianjuta_symbol_type_get_type (void);

GQuark ianjuta_symbol_error_quark     (void);
GType  ianjuta_symbol_get_type        (void);

gboolean ianjuta_symbol_get_boolean (IAnjutaSymbol *obj, IAnjutaSymbolField field, GError **err);

GFile* ianjuta_symbol_get_file (IAnjutaSymbol *obj, GError **err);

const GdkPixbuf * ianjuta_symbol_get_icon (IAnjutaSymbol *obj, GError **err);

gint ianjuta_symbol_get_int (IAnjutaSymbol *obj, IAnjutaSymbolField field, GError **err);

const gchar* ianjuta_symbol_get_string (IAnjutaSymbol *obj, IAnjutaSymbolField field, GError **err);

IAnjutaSymbolType ianjuta_symbol_get_sym_type (IAnjutaSymbol *obj, GError **err);


G_END_DECLS

#endif