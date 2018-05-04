/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#include "search_books.h"
#include "search_books_keynodes.h"
#include "search_book_template.h"

#include "sc_memory_headers.h"


sc_memory_context* s_books_ctx = 0;

sc_event* event_question_search_book_template;


// --------------------- Module ------------------------

_SC_EXT_EXTERN sc_result initialize()
{
    s_books_ctx = sc_memory_context_new(sc_access_lvl_make_min);

    if (search_books_keynodes_initialize() != SC_RESULT_OK)
        return SC_RESULT_ERROR;

    event_question_search_book_template = sc_event_new(s_books_ctx, keynode_question_initiated, SC_EVENT_ADD_OUTPUT_ARC, 0, agent_search_book_template, 0);
    if (event_question_search_book_template == null_ptr)
        return SC_RESULT_ERROR;

    return SC_RESULT_OK;
}

_SC_EXT_EXTERN sc_result shutdown()
{
    if (event_question_search_book_template)
        sc_event_destroy(event_question_search_book_template);

    sc_memory_context_free(s_books_ctx);

    return SC_RESULT_OK;
}