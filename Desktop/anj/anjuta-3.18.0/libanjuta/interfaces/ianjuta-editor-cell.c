/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-editor-cell.c -- Autogenerated from libanjuta.idl
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

/**
 * SECTION:ianjuta-editor-cell
 * @title: IAnjutaEditorCell
 * @short_description: Text editor character cell
 * @see_also:
 * @stability: Unstable
 * @include: libanjuta/interfaces/ianjuta-editor-cell.h
 *
 * Represents a cell in editor. A cell corresponds to a unicode
 * character along with all associated styles (such as colors and font).
 * A cell may or may not have style. If style is supported in the
 * editor, it is assumed all cells will have styles and hence every
 * IAnjutaEditorCell interface instance will have additionally
 * IAnjutaEditorCellStyle implemented.
 */

#include "ianjuta-editor-cell.h"
#include "libanjuta-iface-marshallers.h"

GQuark 
ianjuta_editor_cell_error_quark (void)
{
	static GQuark quark = 0;
	
	if (quark == 0) {
		quark = g_quark_from_static_string ("ianjuta-editor-cell-quark");
	}
	
	return quark;
}

IAnjutaEditorAttribute
ianjuta_editor_cell_get_attribute (IAnjutaEditorCell *obj, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_EDITOR_CELL(obj), 0);
	return IANJUTA_EDITOR_CELL_GET_IFACE (obj)->get_attribute (obj, err);
}

/* Default implementation */
static IAnjutaEditorAttribute
ianjuta_editor_cell_get_attribute_default (IAnjutaEditorCell *obj, GError **err)
{
	g_return_val_if_reached (0);
}

/**
 * ianjuta_editor_cell_get_char:
 * @obj: Self
 * @err: Error propagation and reporting
 *
 * Returns the byte of the unicode character in this cell at given
 * index @char_index. @char_index can vary from 0 to length of the
 * unicode string minus 1. Out of range index is not allowed
 * (asserted) and return is undefined.
 *
 * Since there is dynamic allocation of unicode character string
 * involved in ianjuta_editor_cell_get_character(), this function
 * is mainly useful for fast iteration (such as copying data).
 *
 * Returns: a byte character.
 */
gchar
ianjuta_editor_cell_get_char (IAnjutaEditorCell *obj, gint char_index, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_EDITOR_CELL(obj), 0);
	return IANJUTA_EDITOR_CELL_GET_IFACE (obj)->get_char (obj, char_index, err);
}

/* Default implementation */
static gchar
ianjuta_editor_cell_get_char_default (IAnjutaEditorCell *obj, gint char_index, GError **err)
{
	g_return_val_if_reached (0);
}

/**
 * ianjuta_editor_cell_get_character:
 * @obj: Self
 * @err: Error propagation and reporting
 *
 * Returns the unicode character in this cell. A NULL terminated
 * string is returned that is the multibyte unicode character.
 * NULL is returned if the cell does not have any character.
 *
 * Returns: a newly created string representing the cell's unicode
 * character.
 */
gchar *
ianjuta_editor_cell_get_character (IAnjutaEditorCell *obj, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_EDITOR_CELL(obj), NULL);
	return IANJUTA_EDITOR_CELL_GET_IFACE (obj)->get_character (obj, err);
}

/* Default implementation */
static gchar *
ianjuta_editor_cell_get_character_default (IAnjutaEditorCell *obj, GError **err)
{
	g_return_val_if_reached (NULL);
}

/**
 * ianjuta_editor_cell_get_length:
 * @obj: self
 * @err: Error propagation and reporting.
 *
 * Gets the length of the cell in bytes. That is, length of the
 * unicode character.
 *
 * Returns: Length of the unicode character.
 */
gint
ianjuta_editor_cell_get_length (IAnjutaEditorCell *obj, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_EDITOR_CELL(obj), -1);
	return IANJUTA_EDITOR_CELL_GET_IFACE (obj)->get_length (obj, err);
}

/* Default implementation */
static gint
ianjuta_editor_cell_get_length_default (IAnjutaEditorCell *obj, GError **err)
{
	g_return_val_if_reached (-1);
}

static void
ianjuta_editor_cell_base_init (IAnjutaEditorCellIface* klass)
{
	static gboolean initialized = FALSE;

	klass->get_attribute = ianjuta_editor_cell_get_attribute_default;
	klass->get_char = ianjuta_editor_cell_get_char_default;
	klass->get_character = ianjuta_editor_cell_get_character_default;
	klass->get_length = ianjuta_editor_cell_get_length_default;
	
	if (!initialized) {

		initialized = TRUE;
	}
}

GType
ianjuta_editor_cell_get_type (void)
{
	static GType type = 0;
	if (!type) {
		static const GTypeInfo info = {
			sizeof (IAnjutaEditorCellIface),
			(GBaseInitFunc) ianjuta_editor_cell_base_init,
			NULL, 
			NULL,
			NULL,
			NULL,
			0,
			0,
			NULL
		};
		type = g_type_register_static (G_TYPE_INTERFACE, "IAnjutaEditorCell", &info, 0);
		g_type_interface_add_prerequisite (type, G_TYPE_OBJECT);
	}
	return type;			
}
