/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-editor.h -- Autogenerated from libanjuta.idl
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

#ifndef _IANJUTA_EDITOR_H_
#define _IANJUTA_EDITOR_H_

#include <glib-object.h>
#include <gtk/gtk.h>
#include <libanjuta/interfaces/ianjuta-iterable.h>

G_BEGIN_DECLS

#define IANJUTA_TYPE_EDITOR (ianjuta_editor_get_type ())
#define IANJUTA_EDITOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), IANJUTA_TYPE_EDITOR, IAnjutaEditor))
#define IANJUTA_IS_EDITOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IANJUTA_TYPE_EDITOR))
#define IANJUTA_EDITOR_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), IANJUTA_TYPE_EDITOR, IAnjutaEditorIface))

#define IANJUTA_TYPE_EDITOR_ATTRIBUTE (ianjuta_editor_attribute_get_type())
#define IANJUTA_TYPE_EDITOR_ERROR (ianjuta_editor_error_get_type())

#define IANJUTA_EDITOR_ERROR ianjuta_editor_error_quark()

/**
* IANJUTA_EDITOR_PREF_SCHEMA:
*
* Schema id used to store common editor settings. 
*/
#define	IANJUTA_EDITOR_PREF_SCHEMA	"editor"

/**
* IANJUTA_EDITOR_USE_TABS_KEY:
*
* Boolean key, true is tabs has to be used for indenting.
*/
#define	IANJUTA_EDITOR_USE_TABS_KEY	"use-tabs"

/**
* IANJUTA_EDITOR_TAB_WIDTH_KEY:
*
* Integer key, defines the size of a tabulation in spaces.
*/
#define	IANJUTA_EDITOR_TAB_WIDTH_KEY	"tab-width"

/**
* IANJUTA_EDITOR_INDENT_WIDTH_KEY:
*
* Integer key, defines the number a space for one indentation step.
*/
#define	IANJUTA_EDITOR_INDENT_WIDTH_KEY	"indent-width"


typedef struct _IAnjutaEditor IAnjutaEditor;
typedef struct _IAnjutaEditorIface IAnjutaEditorIface;

  /**
   * IAnjutaEditorAttribute:
   * @IANJUTA_EDITOR_TEXT: Normal text
   * @IANJUTA_EDITOR_KEYWORD: A keyword of the programming language
   * @IANJUTA_EDITOR_COMMENT: A comment
   * @IANJUTA_EDITOR_STRING: A string
   *
   * This enumeration is used to specify the type of text. Note that not all
   * editors implement this.
   */
typedef enum {
	IANJUTA_EDITOR_TEXT,
	IANJUTA_EDITOR_KEYWORD,
	IANJUTA_EDITOR_COMMENT,
	IANJUTA_EDITOR_STRING
} IAnjutaEditorAttribute;

typedef enum {
	IANJUTA_EDITOR_DOESNT_EXIST
} IAnjutaEditorError;


struct _IAnjutaEditorIface {
	GTypeInterface g_iface;
	
	/* Signal */
	void (*backspace) (IAnjutaEditor *obj);
	/* Signal */
	void (*changed) (IAnjutaEditor *obj, IAnjutaIterable *position,  gboolean added,  gint length,  gint lines,  const gchar *text);
	/* Signal */
	void (*char_added) (IAnjutaEditor *obj, IAnjutaIterable *position,  gchar ch);
	/* Signal */
	void (*code_changed) (IAnjutaEditor *obj, IAnjutaIterable *position,  gchar *code);
	/* Signal */
	void (*cursor_moved) (IAnjutaEditor *obj);
	/* Signal */
	void (*glade_callback_add) (IAnjutaEditor *obj, gchar *widget_typename,  gchar *signal_name,  gchar *handler_name,  gchar *object,  gboolean swap,  gboolean after,  gchar *filename);
	/* Signal */
	void (*glade_member_add) (IAnjutaEditor *obj, gchar *widget_typename,  gchar *widget_name,  gchar *filename);
	/* Signal */
	void (*line_marks_gutter_clicked) (IAnjutaEditor *obj, gint location);

	void (*append) (IAnjutaEditor *obj, const gchar *text,  gint length, GError **err);
	void (*erase) (IAnjutaEditor *obj, IAnjutaIterable *position_start,  IAnjutaIterable *position_end, GError **err);
	void (*erase_all) (IAnjutaEditor *obj, GError **err);
	gint (*get_column) (IAnjutaEditor *obj, GError **err);
	gchar* (*get_current_word) (IAnjutaEditor *obj, GError **err);
	IAnjutaIterable* (*get_end_position) (IAnjutaEditor *obj, GError **err);
	gint (*get_indentsize) (IAnjutaEditor *obj, GError **err);
	gint (*get_length) (IAnjutaEditor *obj, GError **err);
	IAnjutaIterable* (*get_line_begin_position) (IAnjutaEditor *obj, gint line, GError **err);
	IAnjutaIterable * (*get_line_end_position) (IAnjutaEditor *obj, gint line, GError **err);
	int (*get_line_from_position) (IAnjutaEditor *obj, IAnjutaIterable *position, GError **err);
	gint (*get_lineno) (IAnjutaEditor *obj, GError **err);
	gint (*get_offset) (IAnjutaEditor *obj, GError **err);
	gboolean (*get_overwrite) (IAnjutaEditor *obj, GError **err);
	IAnjutaIterable* (*get_position) (IAnjutaEditor *obj, GError **err);
	IAnjutaIterable* (*get_position_from_offset) (IAnjutaEditor *obj, gint offset, GError **err);
	IAnjutaIterable* (*get_start_position) (IAnjutaEditor *obj, GError **err);
	gint (*get_tabsize) (IAnjutaEditor *obj, GError **err);
	gchar* (*get_text) (IAnjutaEditor *obj, IAnjutaIterable *begin,  IAnjutaIterable *end, GError **err);
	gchar* (*get_text_all) (IAnjutaEditor *obj, GError **err);
	gboolean (*get_use_spaces) (IAnjutaEditor *obj, GError **err);
	void (*goto_end) (IAnjutaEditor *obj, GError **err);
	void (*goto_line) (IAnjutaEditor *obj, gint lineno, GError **err);
	void (*goto_position) (IAnjutaEditor *obj, IAnjutaIterable *position, GError **err);
	void (*goto_start) (IAnjutaEditor *obj, GError **err);
	void (*insert) (IAnjutaEditor *obj, IAnjutaIterable *position,  const gchar *text,  gint length, GError **err);
	void (*set_auto_indent) (IAnjutaEditor *obj, gboolean auto_indent, GError **err);
	void (*set_indentsize) (IAnjutaEditor *obj, gint indentsize, GError **err);
	void (*set_popup_menu) (IAnjutaEditor *obj, GtkWidget *menu, GError **err);
	void (*set_tabsize) (IAnjutaEditor *obj, gint tabsize, GError **err);
	void (*set_use_spaces) (IAnjutaEditor *obj, gboolean use_spaces, GError **err);

};

GType ianjuta_editor_attribute_get_type (void);
GType ianjuta_editor_error_get_type (void);

GQuark ianjuta_editor_error_quark     (void);
GType  ianjuta_editor_get_type        (void);

void ianjuta_editor_append (IAnjutaEditor *obj, const gchar *text,  gint length, GError **err);

void ianjuta_editor_erase (IAnjutaEditor *obj, IAnjutaIterable *position_start,  IAnjutaIterable *position_end, GError **err);

void ianjuta_editor_erase_all (IAnjutaEditor *obj, GError **err);

gint ianjuta_editor_get_column (IAnjutaEditor *obj, GError **err);

gchar* ianjuta_editor_get_current_word (IAnjutaEditor *obj, GError **err);

IAnjutaIterable* ianjuta_editor_get_end_position (IAnjutaEditor *obj, GError **err);

gint ianjuta_editor_get_indentsize (IAnjutaEditor *obj, GError **err);

gint ianjuta_editor_get_length (IAnjutaEditor *obj, GError **err);

IAnjutaIterable* ianjuta_editor_get_line_begin_position (IAnjutaEditor *obj, gint line, GError **err);

IAnjutaIterable * ianjuta_editor_get_line_end_position (IAnjutaEditor *obj, gint line, GError **err);

int ianjuta_editor_get_line_from_position (IAnjutaEditor *obj, IAnjutaIterable *position, GError **err);

gint ianjuta_editor_get_lineno (IAnjutaEditor *obj, GError **err);

gint ianjuta_editor_get_offset (IAnjutaEditor *obj, GError **err);

gboolean ianjuta_editor_get_overwrite (IAnjutaEditor *obj, GError **err);

IAnjutaIterable* ianjuta_editor_get_position (IAnjutaEditor *obj, GError **err);

IAnjutaIterable* ianjuta_editor_get_position_from_offset (IAnjutaEditor *obj, gint offset, GError **err);

IAnjutaIterable* ianjuta_editor_get_start_position (IAnjutaEditor *obj, GError **err);

gint ianjuta_editor_get_tabsize (IAnjutaEditor *obj, GError **err);

gchar* ianjuta_editor_get_text (IAnjutaEditor *obj, IAnjutaIterable *begin,  IAnjutaIterable *end, GError **err);

gchar* ianjuta_editor_get_text_all (IAnjutaEditor *obj, GError **err);

gboolean ianjuta_editor_get_use_spaces (IAnjutaEditor *obj, GError **err);

void ianjuta_editor_goto_end (IAnjutaEditor *obj, GError **err);

void ianjuta_editor_goto_line (IAnjutaEditor *obj, gint lineno, GError **err);

void ianjuta_editor_goto_position (IAnjutaEditor *obj, IAnjutaIterable *position, GError **err);

void ianjuta_editor_goto_start (IAnjutaEditor *obj, GError **err);

void ianjuta_editor_insert (IAnjutaEditor *obj, IAnjutaIterable *position,  const gchar *text,  gint length, GError **err);

void ianjuta_editor_set_auto_indent (IAnjutaEditor *obj, gboolean auto_indent, GError **err);

void ianjuta_editor_set_indentsize (IAnjutaEditor *obj, gint indentsize, GError **err);

void ianjuta_editor_set_popup_menu (IAnjutaEditor *obj, GtkWidget *menu, GError **err);

void ianjuta_editor_set_tabsize (IAnjutaEditor *obj, gint tabsize, GError **err);

void ianjuta_editor_set_use_spaces (IAnjutaEditor *obj, gboolean use_spaces, GError **err);


G_END_DECLS

#endif
