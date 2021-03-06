/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-editor-language.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_EDITOR_LANGUAGE_H_
#define _IANJUTA_EDITOR_LANGUAGE_H_

#include <glib-object.h>
#include <libanjuta/interfaces/ianjuta-editor.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_EDITOR_LANGUAGE (ianjuta_editor_language_get_type ())
#define IANJUTA_EDITOR_LANGUAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_EDITOR_LANGUAGE, IAnjutaEditorLanguage))
#define IANJUTA_IS_EDITOR_LANGUAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_EDITOR_LANGUAGE))
#define IANJUTA_EDITOR_LANGUAGE_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_EDITOR_LANGUAGE, IAnjutaEditorLanguageIface))

#define IANJUTA_EDITOR_LANGUAGE_ERROR ianjuta_editor_language_error_quark()

typedef struct _IAnjutaEditorLanguage IAnjutaEditorLanguage;
typedef struct _IAnjutaEditorLanguageIface IAnjutaEditorLanguageIface;


struct _IAnjutaEditorLanguageIface {
	IAnjutaEditorIface g_iface;
	
	/* Signal */
	void (*language_changed) (IAnjutaEditorLanguage *obj, const gchar *language);

	const gchar * (*get_language) (IAnjutaEditorLanguage *obj, GError **err);
	const gchar * (*get_language_name) (IAnjutaEditorLanguage *obj, const gchar* language, GError **err);
	const GList* (*get_supported_languages) (IAnjutaEditorLanguage *obj, GError **err);
	void (*set_language) (IAnjutaEditorLanguage *obj, const gchar* language, GError **err);

};


GQuark ianjuta_editor_language_error_quark     (void);
GType  ianjuta_editor_language_get_type        (void);

const gchar * ianjuta_editor_language_get_language (IAnjutaEditorLanguage *obj, GError **err);

const gchar * ianjuta_editor_language_get_language_name (IAnjutaEditorLanguage *obj, const gchar* language, GError **err);

const GList* ianjuta_editor_language_get_supported_languages (IAnjutaEditorLanguage *obj, GError **err);

void ianjuta_editor_language_set_language (IAnjutaEditorLanguage *obj, const gchar* language, GError **err);


G_END_DECLS

#endif
