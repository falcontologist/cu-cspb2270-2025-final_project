// These are the regex patterns with matching construction IDs
// used as a starter set to initialize the patterns vector.
// Some IDs are skipped because the constructions are too noisy or complex for now.

#ifndef PATTERNS_H
#define PATTERNS_H

#include "constructicon-simple.h"

using CausalPattern = CausalConstructicon::CausalPattern;

#include <initializer_list>
#include <regex>

namespace InitialPatterns {

const std::initializer_list<CausalPattern> patterns = {

{
    "<cause> where <effect>",
    std::regex(R"(\bwhere\b)", std::regex::icase),
    {"C001"}
},
{
    "Having <cause>, <effect>",
    std::regex(R"(\bHaving\s*,\b)", std::regex::icase),
    {"C005"}
},
{
    "<effect>, as <cause>",
    std::regex(R"(\b,\s+as\b)", std::regex::icase),
    {"C010"}
},
{
    "<effect> arises from <cause>",
    std::regex(R"(\b(arise|arises|arose|arisen|arising)\s+from\b)", std::regex::icase),
    {"C011"}
},
{
    "<cause> brings on <effect>",
    std::regex(R"(\b(bring|brings|brought|bringing)\s+on\b)", std::regex::icase),
    {"C012"}
},
{
    "<cause> creates <effect>",
    std::regex(R"(\b(create|creates|created|creating)\b)", std::regex::icase),
    {"C013"}
},
{
    "<cause> produces <effect>",
    std::regex(R"(\bproduces\b)", std::regex::icase),
    {"C014"}
},
{
    "<cause> engenders <effect>",
    std::regex(R"(\b(engender|engenders|engendered|engendering)\b)", std::regex::icase),
    {"C015"}
},
{
    "<cause> generates <effect>",
    std::regex(R"(\b(generate|generates|generated|generating)\b)", std::regex::icase),
    {"C016"}
},
{
    "<cause> gives rise to <effect>",
    std::regex(R"(\b(give|gives|gave|given|giving)\s+rise\s+to\b)", std::regex::icase),
    {"C017"}
},
{
    "<cause> incites <effect>",
    std::regex(R"(\b(incite|incites|incited|inciting)\b)", std::regex::icase),
    {"C018"}
},
{
    "<cause> launches <effect>",
    std::regex(R"(\b(launch|launches|launched|launching)\b)", std::regex::icase),
    {"C019"}
},
{
    "<cause> sets off <effect>",
    std::regex(R"(\b(set|sets|setting)\s+off\b)", std::regex::icase),
    {"C020"}
},
{
    "<effect> stems from <cause>",
    std::regex(R"(\b(stem|stems|stemmed|stemming)\s+from\b)", std::regex::icase),
    {"C021"}
},
{
    "<cause> triggers <effect>",
    std::regex(R"(\b(trigger|triggers|triggered|triggering)\b)", std::regex::icase),
    {"C022"}
},
{
    "<cause> sparks <effect>",
    std::regex(R"(\b(spark|sparks|sparked|sparking)\b)", std::regex::icase),
    {"C023"}
},
{
    "<cause> precipitates <effect>",
    std::regex(R"(\b(precipitate|precipitates|precipitated|precipitating)\b)", std::regex::icase),
    {"C024"}
},
{
    "<cause> eliminates <effect>",
    std::regex(R"(\b(eliminate|eliminates|eliminated|eliminating)\b)", std::regex::icase),
    {"C025"}
},
{
    "If <cause>, <effect>",
    std::regex(R"(\bIf\s*,\b)", std::regex::icase),
    {"C027"}
},
{
    "should <cause>, <effect>",
    std::regex(R"(\bshould\s*,\b)", std::regex::icase),
    {"C028"}
},
{
    "<Had cause>, <effect>",
    std::regex(R"(\bHad\b)", std::regex::icase),
    {"C029"}
},
{
    "<cause> allows <effect>",
    std::regex(R"(\b(allow|allows|allowed|allowing)\b)", std::regex::icase),
    {"C030"}
},
{
    "<cause> compels <effect> to <effect>",
    std::regex(R"(\b(compel|compels|compelled|compelling)\s+to\b)", std::regex::icase),
    {"C031"}
},
{
    "<cause> forces <effect>",
    std::regex(R"(\b(force|forces|forced|forcing)\b)", std::regex::icase),
    {"C032"}
},
{
    "<cause> lets <effect> <effect>",
    std::regex(R"(\b(let|lets|letting|allowed)\b)", std::regex::icase),
    {"C033"}
},
{
    "<cause> makes <effect> <effect>",
    std::regex(R"(\b(make|makes|made|making)\b)", std::regex::icase),
    {"C034"}
},
{
    "<cause> obliges <effect> to <effect>",
    std::regex(R"(\b(oblige|obliges|obliged|obliging)\s+to\b)", std::regex::icase),
    {"C035"}
},
{
    "<cause> permits <effect>",
    std::regex(R"(\b(permit|permits|permitted|permitting)\b)", std::regex::icase),
    {"C036"}
},
{
    "<cause> requires <effect>",
    std::regex(R"(\b(require|requires|required|requiring)\b)", std::regex::icase),
    {"C037"}
},
{
    "<cause> forbids <effect>",
    std::regex(R"(\b(forbid|forbids|forbade|forbidding)\b)", std::regex::icase),
    {"C038"}
},
{
    "<cause> prevents <effect>",
    std::regex(R"(\b(prevent|prevents|prevented|preventing)\b)", std::regex::icase),
    {"C039"}
},
{
    "<cause> prohibits <effect>",
    std::regex(R"(\b(prohibit|prohibits|prohibited|prohibiting)\b)", std::regex::icase),
    {"C040"}
},
{
    "Once <cause>, <effect>",
    std::regex(R"(\bOnce\s*,\b)", std::regex::icase),
    {"C047"}
},
{
    "<effect>, since <cause>",
    std::regex(R"(\b,\s+since\b)", std::regex::icase),
    {"C051"}
},
{
    "<cause>, and then <effect>",
    std::regex(R"(\b,\s+and\s+then\b)", std::regex::icase),
    {"C052"}
},
{
    "the aftermath of <cause> is <effect>",
    std::regex(R"(\bthe\s+aftermath\s+of\s+.*?\s+is\b)", std::regex::icase),
    {"C053"}
},
{
    "<effect> takes <cause>",
    std::regex(R"(\btakes\b)", std::regex::icase),
    {"C065"}
},
{
    "<effect> comes after <cause>",
    std::regex(R"(\b(come|comes|coming)\s+after\b)", std::regex::icase),
    {"C066"}
},
{
    "<effect> follows <cause>",
    std::regex(R"(\b(follow|follows|followed|following)\b)", std::regex::icase),
    {"C067"}
},
{
    "<effect> is conditioned on <cause>",
    std::regex(R"(\bis\s+conditioned\s+on\b)", std::regex::icase),
    {"C070"}
},
{
    "<effect> is contingent on <cause>",
    std::regex(R"(\bis\s+contingent\s+on\b)", std::regex::icase),
    {"C071"}
},
{
    "<cause> is critical to <effect>",
    std::regex(R"(\bis\s+critical\s+to\b)", std::regex::icase),
    {"C072"}
},
{
    "<cause> is essential to <effect>",
    std::regex(R"(\bis\s+essential\s+to\b)", std::regex::icase),
    {"C073"}
},
{
    "<cause> is responsible for <effect>",
    std::regex(R"(\bis\s+responsible\s+for\b)", std::regex::icase),
    {"C074"}
},
{
    "<cause> is vital to <effect>",
    std::regex(R"(\bis\s+vital\s+to\b)", std::regex::icase),
    {"C075"}
},
{
    "<cause>, and consequently, <effect>",
    std::regex(R"(\b,\s+and\s+consequently,\b)", std::regex::icase),
    {"C076"}
},
{
    "<cause>; hence, <effect>",
    std::regex(R"(\b;\s+hence,\b)", std::regex::icase),
    {"C077"}
},
{
    "<cause>; therefore, <effect>",
    std::regex(R"(\b;\s+therefore,\b)", std::regex::icase),
    {"C078"}
},
{
    "<cause> is why <effect>",
    std::regex(R"(\bis\s+why\b)", std::regex::icase),
    {"C079"}
},
{
    "<cause>, so <effect>",
    std::regex(R"(\b,\s+so\b)", std::regex::icase),
    {"C099"}
},
{
    "<cause>, and thus <effect>",
    std::regex(R"(\b,\s+and\s+thus\b)", std::regex::icase),
    {"C100"}
},
{
    "<effect> because <cause>",
    std::regex(R"(\bbecause\b)", std::regex::icase),
    {"C102"}
},
{
    "Given <cause>, <effect>",
    std::regex(R"(\bGiven\s*,\b)", std::regex::icase),
    {"C104"}
},
{
    "In an attempt to <cause>, <effect>",
    std::regex(R"(\bIn\s+an\s+attempt\s+to\s*,\b)", std::regex::icase),
    {"C105"}
},
{
    "<effect> lest <cause>",
    std::regex(R"(\blest\b)", std::regex::icase),
    {"C106"}
},
{
    "Now that <cause>, <effect>",
    std::regex(R"(\bNow\s+that\s*,\b)", std::regex::icase),
    {"C107"}
},
{
    "<effect> so <cause>",
    std::regex(R"(\bso\b)", std::regex::icase),
    {"C108"}
},
{
    "<effect> thanks to <cause>",
    std::regex(R"(\bthanks\s+to\b)", std::regex::icase),
    {"C109"}
},
{
    "<cause> else <effect>",
    std::regex(R"(\belse\b)", std::regex::icase),
    {"C110"}
},
{
    "<effect> unless <cause>",
    std::regex(R"(\bunless\b)", std::regex::icase),
    {"C111"}
},
{
    "<cause> is DET cause of <effect>",
    std::regex(R"(\bis\s+(the|a|an|this|that|these|those)\s+cause\s+of\b)", std::regex::icase),
    {"C112"}
},
{
    "DET consequence of <cause> is <effect>",
    std::regex(R"(\b(the|a|an|this|that|these|those)\s+consequence\s+of\s+.*?\s+is\b)", std::regex::icase),
    {"C113"}
},
{
    "DET effect of <cause> is <effect>",
    std::regex(R"(\b(the|a|an|this|that|these|those)\s+effect\s+of\s+.*?\s+is\b)", std::regex::icase),
    {"C114"}
},
{
    "<cause> is grounds for <effect>",
    std::regex(R"(\bis\s+grounds\s+for\b)", std::regex::icase),
    {"C115"}
},
{
    "the implications of <cause> are <effect>",
    std::regex(R"(\bthe\s+implications\s+of\s+.*?\s+are\b)", std::regex::icase),
    {"C116"}
},
{
    "<cause> is the key to <effect>",
    std::regex(R"(\bis\s+the\s+key\s+to\b)", std::regex::icase),
    {"C117"}
},
{
    "<cause> is DET necessary condition of <effect>",
    std::regex(R"(\bis\s+(the|a|an|this|that|these|those)\s+necessary\s+condition\s+of\b)", std::regex::icase),
    {"C118"}
},
{
    "DET reason [that] <effect> is <cause>",
    std::regex(R"(\b(the|a|an|this|that|these|those)\s+reason\s+(that\s+)?\s*.*?\s+is\b)", std::regex::icase),
    {"C119"}
},
{
    "DET reason for <effect> is <cause>",
    std::regex(R"(\b(the|a|an|this|that|these|those)\s+reason\s+for\s+.*?\s+is\b)", std::regex::icase),
    {"C120"}
},
{
    "<cause> is reason to <effect>",
    std::regex(R"(\bis\s+reason\s+to\b)", std::regex::icase),
    {"C121"}
},
{
    "<cause> is reason why <effect>",
    std::regex(R"(\bis\s+reason\s+why\b)", std::regex::icase),
    {"C122"}
},
{
    "<effect> is DET result of <cause>",
    std::regex(R"(\bis\s+(the|a|an|this|that|these|those)\s+result\s+of\b)", std::regex::icase),
    {"C123"}
},
{
    "<cause> is condition of <effect>",
    std::regex(R"(\bis\s+condition\s+of\b)", std::regex::icase),
    {"C124"}
},
{
    "<effect> because of <cause>",
    std::regex(R"(\bbecause\s+of\b)", std::regex::icase),
    {"C125"}
},
{
    "<effect> by reason of <cause>",
    std::regex(R"(\bby\s+reason\s+of\b)", std::regex::icase),
    {"C127"}
},
{
    "<effect> for the sake of <cause>",
    std::regex(R"(\bfor\s+the\s+sake\s+of\b)", std::regex::icase),
    {"C129"}
},
{
    "In light of <cause>, <effect>",
    std::regex(R"(\bIn\s+light\s+of\s*,\b)", std::regex::icase),
    {"C133"}
},
{
    "<cause> ensures <effect>",
    std::regex(R"(\bensures\b)", std::regex::icase),
    {"C139"}
},
{
    "<cause> guarantees <effect>",
    std::regex(R"(\bguarantees\b)", std::regex::icase),
    {"C140"}
},
{
    "<cause> makes certain <effect>",
    std::regex(R"(\bmakes\s+certain\b)", std::regex::icase),
    {"C141"}
},
{
    "<cause> assures <effect>",
    std::regex(R"(\b(assure|assures|assured|assuring)\b)", std::regex::icase),
    {"C142"}
},
{
    "NP attributes <effect> to <cause>",
    std::regex(R"(\b(attribute|attributes|attributed|attributing)\s+to\b)", std::regex::icase),
    {"C143"}
},
{
    "NP blames <cause> for <effect>",
    std::regex(R"(\b(blame|blames|blamed|blaming)\s+for\b)", std::regex::icase),
    {"C144"}
},
{
    "<cause> brings <effect> to <effect>",
    std::regex(R"(\b(bring|brings|brought|bringing)\s+to\b)", std::regex::icase),
    {"C145"}
},
{
    "<cause> causes <effect>",
    std::regex(R"(\b(cause|causes|caused|causing)\b)", std::regex::icase),
    {"C146"}
},
{
    "<effect> comes from <cause>",
    std::regex(R"(\b(come|comes|coming)\s+from\b)", std::regex::icase),
    {"C147"}
},
{
    "<cause> contributes to <effect>",
    std::regex(R"(\b(contribute|contributes|contributed|contributing)\s+to\b)", std::regex::icase),
    {"C148"}
},
{
    "<effect> depends on <cause>",
    std::regex(R"(\b(depend|depends|depended|depending)\s+on\b)", std::regex::icase),
    {"C149"}
},
{
    "<cause> drives <effect>",
    std::regex(R"(\b(drive|drives|driving)\b)", std::regex::icase),
    {"C150"}
},
{
    "<cause> eases <effect>",
    std::regex(R"(\b(ease|eases|eased|easing)\b)", std::regex::icase),
    {"C151"}
},
{
    "<cause> enables <effect>",
    std::regex(R"(\b(enable|enables|enabled|enabling)\b)", std::regex::icase),
    {"C152"} 
},
{
    "the probable cause of <effect> was <cause",
    std::regex(R"(\bthe\s+probable\s+cause\s+of\b)", std::regex::icase),
    {"M001"}
},
};

} 

#endif 