/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-editor-selection.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_EDITOR_SELECTION_H_
#define _IANJUTA_EDITOR_SELECTION_H_

#include <glib-object.h>
#include <libanjuta/interfaces/ianjuta-editor-cell.h>
#include <libanjuta/interfaces/ianjuta-editor.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_EDITOR_SELECTION (ianjuta_editor_selection_get_type ())
#define IANJUTA_EDITOR_SELECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_EDITOR_SELECTION, IAnjutaEditorSelection))
#define IANJUTA_IS_EDITOR_SELECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_EDITOR_SELECTION))
#define IANJUTA_EDITOR_SELECTION_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_EDITOR_SELECTION, IAnjutaEditorSelectionIface))

#define IANJUTA_EDITOR_SELECTION_ERROR ianjuta_editor_selection_error_quark()

typedef struct _IAnjutaEditorSelection IAnjutaEditorSelection;
typedef struct _IAnjutaEditorSelectionIface IAnjutaEditorSelectionIface;


struct _IAnjutaEditorSelectionIface {
	IAnjutaEditorIface g_iface;
	

	gchar* (*get) (IAnjutaEditorSelection *obj, GError **err);
	IAnjutaIterable* (*get_end) (IAnjutaEditorSelection *obj, GError **err);
	IAnjutaIterable* (*get_start) (IAnjutaEditorSelection *obj, GError **err);
	gboolean (*has_selection) (IAnjutaEditorSelection *obj, GError **err);
	void (*replace) (IAnjutaEditorSelection *obj, const gchar *text,  gint length, GError **err);
	void (*select_all) (IAnjutaEditorSelection *obj, GError **err);
	void (*select_block) (IAnjutaEditorSelection *obj, GError **err);
	void (*select_function) (IAnjutaEditorSelection *obj, GError **err);
	void (*set) (IAnjutaEditorSelection *obj, IAnjutaIterable* start,  IAnjutaIterable* end,  gboolean scroll, GError **err);

};


GQuark ianjuta_editor_selection_error_quark     (void);
GType  ianjuta_editor_selection_get_type        (void);

gchar* ianjuta_editor_selection_get (IAnjutaEditorSelection *obj, GError **err);

IAnjutaIterable* ianjuta_editor_selection_get_end (IAnjutaEditorSelection *obj, GError **err);

IAnjutaIterable* ianjuta_editor_selection_get_start (IAnjutaEditorSelection *obj, GError **err);

gboolean ianjuta_editor_selection_has_selection (IAnjutaEditorSelection *obj, GError **err);

void ianjuta_editor_selection_replace (IAnjutaEditorSelection *obj, const gchar *text,  gint length, GError **err);

void ianjuta_editor_selection_select_all (IAnjutaEditorSelection *obj, GError **err);

void ianjuta_editor_selection_select_block (IAnjutaEditorSelection *obj, GError **err);

void ianjuta_editor_selection_select_function (IAnjutaEditorSelection *obj, GError **err);

void ianjuta_editor_selection_set (IAnjutaEditorSelection *obj, IAnjutaIterable* start,  IAnjutaIterable* end,  gboolean scroll, GError **err);


G_END_DECLS

#endif
