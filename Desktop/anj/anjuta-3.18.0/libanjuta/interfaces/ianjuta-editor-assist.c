/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-editor-assist.c -- Autogenerated from libanjuta.idl
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
 * SECTION:ianjuta-editor-assist
 * @title: IAnjutaEditorAssist
 * @short_description: Text editor assist interface
 * @see_also:
 * @stability: Unstable
 * @include: libanjuta/interfaces/ianjuta-editor-assist
 *
 */

#include "ianjuta-editor-assist.h"
#include "libanjuta-iface-marshallers.h"

GQuark 
ianjuta_editor_assist_error_quark (void)
{
	static GQuark quark = 0;
	
	if (quark == 0) {
		quark = g_quark_from_static_string ("ianjuta-editor-assist-quark");
	}
	
	return quark;
}

     /*
      * ianjuta_editor_assist_add:
      * @obj: self
      * @provider: a IAnjutaProvider
      * @err: Error handling
      *
      * Add a provider to the list of completion providers
      */
void
ianjuta_editor_assist_add (IAnjutaEditorAssist *obj, IAnjutaProvider* provider, GError **err)
{
	g_return_if_fail (IANJUTA_IS_EDITOR_ASSIST(obj));
	g_return_if_fail ((provider == NULL) ||IANJUTA_IS_PROVIDER(provider));
	IANJUTA_EDITOR_ASSIST_GET_IFACE (obj)->add (obj, provider, err);
}

/* Default implementation */
static void
ianjuta_editor_assist_add_default (IAnjutaEditorAssist *obj, IAnjutaProvider* provider, GError **err)
{
	g_return_if_reached ();
}

     /*
      * ianjuta_editor_assist_invoke:
      * @obj: self
      * @provider: a IAnjutaProvider (can be NULL to use all providers)
      * @err: Error handling
      *
      * Force invokation of a provider at the current cursor position.
      * That means that ianjuta_provider_populate() will be called on the
      * provider.
      */
void
ianjuta_editor_assist_invoke (IAnjutaEditorAssist *obj, IAnjutaProvider* provider, GError **err)
{
	g_return_if_fail (IANJUTA_IS_EDITOR_ASSIST(obj));
	g_return_if_fail ((provider == NULL) ||IANJUTA_IS_PROVIDER(provider));
	IANJUTA_EDITOR_ASSIST_GET_IFACE (obj)->invoke (obj, provider, err);
}

/* Default implementation */
static void
ianjuta_editor_assist_invoke_default (IAnjutaEditorAssist *obj, IAnjutaProvider* provider, GError **err)
{
	g_return_if_reached ();
}

     /**
      * ianjuta_editor_assist_proposals:
      * @obj: self
      * @provider: a IAnjutaProvider
      * @proposals: (element-type IAnjutaEditorAssistProposal): a list of IAnjutaProposals
      * @pre_word: the word before the cursor
      * @finished: whether is was the last call in an async operation
      * @err: Error handling
      *
      * Add the list of proposals for the current population. You can add
      * proposals async as long as the last call sets finished to TRUE. That
      * is usually called by the IAnjutaProvider after it was triggered by
      * ianjuta_provider_populate()
      *
      */
void
ianjuta_editor_assist_proposals (IAnjutaEditorAssist *obj, IAnjutaProvider* provider,   GList* proposals,   const gchar* pre_word,   gboolean finished, GError **err)
{
	g_return_if_fail (IANJUTA_IS_EDITOR_ASSIST(obj));
	g_return_if_fail ((provider == NULL) ||IANJUTA_IS_PROVIDER(provider));
	IANJUTA_EDITOR_ASSIST_GET_IFACE (obj)->proposals (obj, provider, proposals, pre_word, finished, err);
}

/* Default implementation */
static void
ianjuta_editor_assist_proposals_default (IAnjutaEditorAssist *obj, IAnjutaProvider* provider,   GList* proposals,   const gchar* pre_word,   gboolean finished, GError **err)
{
	g_return_if_reached ();
}

     /*
      * ianjuta_editor_assist_remove:
      * @obj: self
      * @provider: a IAnjutaProvider
      * @err: Error handling
      *
      * Remove a provider from the list of completion providers
      */
void
ianjuta_editor_assist_remove (IAnjutaEditorAssist *obj, IAnjutaProvider* provider, GError **err)
{
	g_return_if_fail (IANJUTA_IS_EDITOR_ASSIST(obj));
	g_return_if_fail ((provider == NULL) ||IANJUTA_IS_PROVIDER(provider));
	IANJUTA_EDITOR_ASSIST_GET_IFACE (obj)->remove (obj, provider, err);
}

/* Default implementation */
static void
ianjuta_editor_assist_remove_default (IAnjutaEditorAssist *obj, IAnjutaProvider* provider, GError **err)
{
	g_return_if_reached ();
}

static void
ianjuta_editor_assist_base_init (IAnjutaEditorAssistIface* klass)
{
	static gboolean initialized = FALSE;

	klass->add = ianjuta_editor_assist_add_default;
	klass->invoke = ianjuta_editor_assist_invoke_default;
	klass->proposals = ianjuta_editor_assist_proposals_default;
	klass->remove = ianjuta_editor_assist_remove_default;
	
	if (!initialized) {

		    /**
		 * IAnjutaEditorAssist::cancelled:
		 * @obj: Self
		 *
		 * This signal is emitted when the autocompletion is cancelled due to various
		 * reasons. The provider should avoid to call ianjuta_editor_assist_proposals() after
		 * this signal.
		 */
		g_signal_new ("cancelled",
			IANJUTA_TYPE_EDITOR_ASSIST,
			G_SIGNAL_RUN_LAST,
			G_STRUCT_OFFSET (IAnjutaEditorAssistIface, cancelled),
			NULL, NULL,
			libanjuta_iface_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE,
			0,
			NULL);


		initialized = TRUE;
	}
}

GType
ianjuta_editor_assist_get_type (void)
{
	static GType type = 0;
	if (!type) {
		static const GTypeInfo info = {
			sizeof (IAnjutaEditorAssistIface),
			(GBaseInitFunc) ianjuta_editor_assist_base_init,
			NULL, 
			NULL,
			NULL,
			NULL,
			0,
			0,
			NULL
		};
		type = g_type_register_static (G_TYPE_INTERFACE, "IAnjutaEditorAssist", &info, 0);
		g_type_interface_add_prerequisite (type, IANJUTA_TYPE_EDITOR);
	}
	return type;			
}
