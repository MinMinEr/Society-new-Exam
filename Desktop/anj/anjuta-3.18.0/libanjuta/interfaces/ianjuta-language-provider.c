/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  ianjuta-language-provider.c -- Autogenerated from libanjuta.idl
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
 * SECTION:ianjuta-language-provider
 * @title: IAnjutaLanguageProvider
 * @short_description: Provider for autocompletion features
 * @see_also:
 * @stability: Unstable
 * @include: libanjuta/interfaces/ianjuta-language-provider.h
 */

#include "ianjuta-language-provider.h"
#include "libanjuta-iface-marshallers.h"

GQuark 
ianjuta_language_provider_error_quark (void)
{
	static GQuark quark = 0;
	
	if (quark == 0) {
		quark = g_quark_from_static_string ("ianjuta-language-provider-quark");
	}
	
	return quark;
}

/**
 * ianjuta_language_provider_get_calltip_cache:
 * @obj: Self
 * @call_context: name of the method to show a calltip
 * @err: Error propagation
 *
 * Searches for a calltip in the cache
 *
 * Returns: (element-type utf8) (transfer container): tips for the
 *          searched name of the method from the cache,
 *          NULL if nothing found
 */
GList*
ianjuta_language_provider_get_calltip_cache (IAnjutaLanguageProvider *obj, gchar* call_context, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_LANGUAGE_PROVIDER(obj), 0);
	return IANJUTA_LANGUAGE_PROVIDER_GET_IFACE (obj)->get_calltip_cache (obj, call_context, err);
}

/* Default implementation */
static GList*
ianjuta_language_provider_get_calltip_cache_default (IAnjutaLanguageProvider *obj, gchar* call_context, GError **err)
{
	g_return_val_if_reached (NULL);
}

/**
 * ianjuta_language_provider_get_calltip_context:
 * @obj: Self
 * @iter: current cursor position
 * @err: Error propagation
 *
 * Searches for a calltip context
 *
 * Returns: name of the method to show a calltip for or NULL
 */
gchar*
ianjuta_language_provider_get_calltip_context (IAnjutaLanguageProvider *obj, IAnjutaIterable* iter, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_LANGUAGE_PROVIDER(obj), NULL);
	g_return_val_if_fail ((iter == NULL) ||IANJUTA_IS_ITERABLE(iter), NULL);
	return IANJUTA_LANGUAGE_PROVIDER_GET_IFACE (obj)->get_calltip_context (obj, iter, err);
}

/* Default implementation */
static gchar*
ianjuta_language_provider_get_calltip_context_default (IAnjutaLanguageProvider *obj, IAnjutaIterable* iter, GError **err)
{
	g_return_val_if_reached (NULL);
}

/**
 * ianjuta_language_provider_new_calltip:
 * @obj: Self
 * @call_context: name of the method to create a new calltip
 * @iter: current cursor position
 * @err: Error propagation
 *
 * Creates a new calltip
 */
void
ianjuta_language_provider_new_calltip (IAnjutaLanguageProvider *obj, gchar* call_context,   IAnjutaIterable* iter, GError **err)
{
	g_return_if_fail (IANJUTA_IS_LANGUAGE_PROVIDER(obj));
	g_return_if_fail ((iter == NULL) ||IANJUTA_IS_ITERABLE(iter));
	IANJUTA_LANGUAGE_PROVIDER_GET_IFACE (obj)->new_calltip (obj, call_context, iter, err);
}

/* Default implementation */
static void
ianjuta_language_provider_new_calltip_default (IAnjutaLanguageProvider *obj, gchar* call_context,   IAnjutaIterable* iter, GError **err)
{
	g_return_if_reached ();
}

/**
 * ianjuta_language_provider_populate_completions:
 * @obj: Self
 * @iter: the text iter where the provider should be populated
 * @err: Error propagation and reporting.
 *
 * Show completion for the context at position @iter. The provider should
 * call ianjuta_editor_assist_proposals here to add proposals to the list.
 *
 * Note that this is called after every character typed and the list of proposals
 * has to be completely renewed.
 *
 * Returns: (transfer full) (allow-none): the iter where the provider populated, NULL otherwise
 */
IAnjutaIterable*
ianjuta_language_provider_populate_completions (IAnjutaLanguageProvider *obj, IAnjutaIterable* iter, GError **err)
{
	g_return_val_if_fail (IANJUTA_IS_LANGUAGE_PROVIDER(obj), NULL);
	g_return_val_if_fail ((iter == NULL) ||IANJUTA_IS_ITERABLE(iter), NULL);
	return IANJUTA_LANGUAGE_PROVIDER_GET_IFACE (obj)->populate_completions (obj, iter, err);
}

/* Default implementation */
static IAnjutaIterable*
ianjuta_language_provider_populate_completions_default (IAnjutaLanguageProvider *obj, IAnjutaIterable* iter, GError **err)
{
	g_return_val_if_reached (NULL);
}

static void
ianjuta_language_provider_base_init (IAnjutaLanguageProviderIface* klass)
{
	static gboolean initialized = FALSE;

	klass->get_calltip_cache = ianjuta_language_provider_get_calltip_cache_default;
	klass->get_calltip_context = ianjuta_language_provider_get_calltip_context_default;
	klass->new_calltip = ianjuta_language_provider_new_calltip_default;
	klass->populate_completions = ianjuta_language_provider_populate_completions_default;
	
	if (!initialized) {

		initialized = TRUE;
	}
}

GType
ianjuta_language_provider_get_type (void)
{
	static GType type = 0;
	if (!type) {
		static const GTypeInfo info = {
			sizeof (IAnjutaLanguageProviderIface),
			(GBaseInitFunc) ianjuta_language_provider_base_init,
			NULL, 
			NULL,
			NULL,
			NULL,
			0,
			0,
			NULL
		};
		type = g_type_register_static (G_TYPE_INTERFACE, "IAnjutaLanguageProvider", &info, 0);
		g_type_interface_add_prerequisite (type, IANJUTA_TYPE_PROVIDER);
	}
	return type;			
}
