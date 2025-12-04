
// These are the non-noisy, non-complex causal constructions from the reference set
// used as a starter set to initialize the constructions vector.
// Some IDs are skipped because the constructions are too noisy or complex for now.

#ifndef CONSTRUCTIONS_H
#define CONSTRUCTIONS_H

#include "constructicon-simple.h"
#include <initializer_list>

using CausalConstruction = CausalConstructicon::CausalConstruction;

namespace InitialConstructions { 

const std::initializer_list<CausalConstruction> constructions = {
    
{
    "C001",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> where <effect>",
    "Where regulators cozy up with CEOs, corruption abounds."
},
{
    "C002",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> amid <cause>",
    "Banks and stores closed yesterday amid growing fears of violence."
},
{
    "C003",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "With <cause>, <effect>",
    "With supplies running low, we didn't even make a fire that night."
},
{
    "C004",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "Without <cause>, <effect>",
    "Without better regulation, the same problem will recur."
},
{
    "C005",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "Having <cause>, <effect>",
    "Having looked at the older document, the faculty believed that a middle ground might be appropriate."
},
{
    "C006",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "the <more cause>, the <more effect>",
    "The more the wave rose, the faster we ran."
},
{
    "C007",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> every time <cause>",
    "Every time I see that image, I cringe."
},
{
    "C008",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "whenever <cause>, <effect>",
    "Whenever I smile at my son, he always smiles back."
},
{
    "C009",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "Anytime <cause>, <effect>",
    "Anytime the power flickers, our computers restart."
},
{
    "C010",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect>, as <cause>",
    "As science has yet to prove or disprove the existence of a divine power, and probably never will, I will use my gift of reason.  As the power increased, the rotor spun faster."
},
{
    "C011",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> arises from <cause>",
    "A slight unpleasantness arose from this discussion."
},
{
    "C012",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> brings on <effect>",
    "Eating ice cream too fast can bring on a headache."
},
{
    "C013",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> creates <effect>",
    "The immediate crisis created by the run on Bear Stearns has passed."
},
{
    "C014",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> produces <effect>",
    "No conventional drugs had produced any significant change."
},
{
    "C015",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> engenders <effect>",
    "Regulatory competition can engender a race to the bottom."
},
{
    "C016",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> generates <effect>",
    "These harsh enforcement provisions will undoubtedly generate abuses and mistreatment."
},
{
    "C017",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> gives rise to <effect>",
    "Their decisions gave rise to subsequent arguments."
},
{
    "C018",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> incites <effect>",
    "The news incited widespread fear and paranoia."
},
{
    "C019",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> launches <effect>",
    "The scandal launched a massive rebellion."
},
{
    "C020",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> sets off <effect>",
    "The attack set off great unrest among the people."
},
{
    "C021",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> stems from <cause>",
    "Many of the universities' problems stem from rapid expansion."
},
{
    "C022",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> triggers <effect>",
    "Their small protest triggered a mass demonstration."
},
{
    "C023",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> sparks <effect>",
    "Unrest in the Middle East sparked a global oil shock."
},
{
    "C024",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> precipitates <effect>",
    "Every shudder had precipitated a dusting of granules onto the floor."
},
{
    "C025",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> eliminates <effect>",
    "We must eliminate future bank runs."
},
{
    "C026",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> if <effect> is to <effect>",
    "We'll need a collaborative effort if we are to have a successful outcome."
},
{
    "C027",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "If <cause>, <effect>",
    "If I don't get an A on the final, I can't pass the course."
},
{
    "C028",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "should <cause>, <effect>",
    "Should you wish to cancel your order, please contact our customer service department."
},
{
    "C029",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<Had cause>, <effect>",
    "Had I known, I'd have come with you."
},
{
    "C030",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> allows <effect>",
    "Plastics have allowed an enormous range of new inventions."
},
{
    "C031",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> compels <effect> to <effect>",
    "The news compelled him to act."
},
{
    "C032",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> forces <effect>",
    "Senator Brownback forces there to be a contradiction between faith and reason."
},
{
    "C033",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> lets <effect> <effect>",
    "I let the creature climb up my shirt."
},
{
    "C034",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> makes <effect> <effect>",
    "This bill seeks to make regulation more efficient."
},
{
    "C035",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> obliges <effect> to <effect>",
    "Her financial problems obliged her to get another job."
},
{
    "C036",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> permits <effect>",
    "The unusually calm winds permitted a much more gentle sailing style."
},
{
    "C037",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> requires <effect>",
    "Politeness usually requires that the speaker shall mention the addressed person first, and himself last."
},
{
    "C038",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> forbids <effect>",
    "Her sense of modesty forbids her to speak up."
},
{
    "C039",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> prevents <effect>",
    "A market sensitive regulatory authority not only prevents some of the problems, but is pro-market."
},
{
    "C040",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> prohibits <effect>",
    "The cost of safety glass often prohibits its use in private buildings."
},
{
    "C041",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<adequate cause> to <effect>",
    "We have adequate time to listen to this."
},
{
    "C042",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<enough cause> to <effect>",
    "We have enough time to listen to this."
},
{
    "C043",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<so cause> that <effect>",
    "She got so lonely that she decided to watch TV."
},
{
    "C044",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<sufficient cause> to <effect>",
    "It must contain sufficient criteria to prevent cost to the taxpayer to the greatest extent possible."
},
{
    "C045",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<insufficient cause> to <effect>",
    "There is insufficient evidence to prove his guilt."
},
{
    "C046",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<too cause> to <effect>",
    "Virtually every primary dealer is considered too big or too interconnected to fail."
},
{
    "C047",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "Once <cause>, <effect>",
    "Once we started seeing results, we began to relax."
},
{
    "C048",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> in advance of <cause>",
    "What these reflections mean for Catholics worldwide is under discussion in advance of the upcoming synod of bishops."
},
{
    "C049",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "in the aftermath of <cause>, <effect>",
    "In the aftermath of the vote, the sense that the Union is fracturing cannot be ignored."
},
{
    "C050",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> in the wake of <cause>",
    "In the wake of the storm, there were many broken tree limbs."
},
{
    "C051",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect>, since <cause>",
    "Religion should not be substituted for science, nor the reverse, since they deal with different domains."
},
{
    "C052",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause>, and then <effect>",
    "I'll buy some peanut butter, and only then can I make a sandwich."
},
{
    "C053",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "the aftermath of <cause> is <effect>",
    "Residents are still dealing with the aftermath of the storm."
},
{
    "C054",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> at <cause>",
    "I jumped at the sound of the bell."
},
{
    "C055",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "Before <effect>, <cause>",
    "Before he can come to the US, he'll have to get a visa."
},
{
    "C056",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "following <cause>, <effect>",
    "Following the storm, utility companies swept through looking for precarious tree limbs."
},
{
    "C057",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "Over <time-unit of cause>, <effect>",
    "Over 3000 years of domestication, silkworms have lost their flight skills."
},
{
    "C058",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "upon <cause>, <effect>",
    "Upon hearing the news, she burst into tears."
},
{
    "C059",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "after <cause>, <effect>",
    "After I had a drink, I felt much better."
},
{
    "C060",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "Before <cause>, <effect>",
    "Before I came to the US, I never bothered to smile for photos."
},
{
    "C061",
    CausalDegree::Inhibit,
    CausalOrder::EC,
    "<effect> until <cause>",
    "We can't let you go until we see improvement."
},
{
    "C062",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "during <cause>, <effect>",
    "During the thunderstorm, we all hunkered down inside."
},
{
    "C063",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "while <cause>, <effect>",
    "While the family was on vacation, the burgler was able to come and go as he pleased.  While recovering, his batting average was significantly lower."
},
{
    "C064",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "within <time-unit> of <cause>, <effect>",
    "Within two minutes of drinking the cocktail, Tom was dead."
},
{
    "C065",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> takes <cause>",
    "It will take ten men to construct this building."
},
{
    "C066",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> comes after <cause>",
    "The investigation comes after government watchdogs raised red flags about classified material possibly being shared."
},
{
    "C067",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> follows <cause>",
    "The plunge in stock prices followed a disappointing earnings report."
},
{
    "C068",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "when <cause>, <effect>",
    "When they told me the price, I nearly fainted."
},
{
    "C069",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> as long as <cause>",
    "As long as you feed him, he'll be cooperative."
},
{
    "C070",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> is conditioned on <cause>",
    "Our participation is conditional on your good behavior."
},
{
    "C071",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> is contingent on <cause>",
    "Resolution of the conflict was contingent on the signing of a ceasefire agreement."
},
{
    "C072",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> is critical to <effect>",
    "Transparency is critical to a fair judicial system."
},
{
    "C073",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> is essential to <effect>",
    "Transparency is essential to a fair judicial system."
},
{
    "C074",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> is responsible for <effect>",
    "Residential use is responsible for a surprisingly small amount of the water shortage."
},
{
    "C075",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> is vital to <effect>",
    "Good financial accounts are vital to the success of any enterprise."
},
{
    "C076",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause>, and consequently, <effect>",
    "They often avoid reading and consequently fail to improve."
},
{
    "C077",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause>, hence, <effect>",
    "Today there will be a stiff breeze and hence a high windchill."
},
{
    "C078",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause>, therefore, <effect>",
    "Therefore, we should consider how to most appropriately give the Fed the necessary authority."
},
{
    "C079",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> is why <effect>",
    "That is why I believe in regulation properly done."
},
{
    "C080",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "For <effect> to <effect>, <cause>",
    "For market discipline to be effective, market participants must not expect that lending from the Fed is readily available.  We'll need a lot of input to create the best product.  To get good ice cream, you have to go to Mercurio's."
},
{
    "C081",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "As a result, <effect>",
    "As a result, vital legislation involving the budget, elections, and amendments remains trapped."
},
{
    "C082",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> by virtue of <cause>",
    "They hold the posts by virtue of family connections."
},
{
    "C083",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> clears the way for <effect>",
    "This FCC vote clears the way for lower-cost mobile data."
},
{
    "C084",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "For <DET purpose=effect>, <cause>",
    "For that reason, I look forward to hearing from today's witnesses.  I need to know for tax purposes."
},
{
    "C085",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "For <DET reason=cause>, <effect>",
    "For that reason, I look forward to hearing from today's witnesses."
},
{
    "C086",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> in case <cause>",
    "He placed a suitcase in the corner in case of an emergency trip to the hospital."
},
{
    "C087",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> in an effort to <cause>",
    "I climbed the ladder in an effort to see into the attic."
},
{
    "C088",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> in response to <cause>",
    "In response to heavy criticism, the CDC rescinded its recommendations."
},
{
    "C089",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "In the face of <cause>, <effect>",
    "The debate has sharpened in the face of concerns about the safety of formaldehyde-treated flooring."
},
{
    "C090",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "in view of <cause>, <effect>",
    "In view of this new evidence, we would like to reconsider our decision."
},
{
    "C091",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> on grounds of <cause>",
    "Participants were chosen on the grounds of their past work."
},
{
    "C092",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> opens the way for <effect>",
    "This decision opens the way for much broader application of the law."
},
{
    "C093",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> opens the door for <effect>",
    "This opens doors to opportunity."
},
{
    "C094",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> paves the way for <effect>",
    "Her success paves the way for the county's next wave of female wrestlers."
},
{
    "C095",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> so as to <cause>",
    "He nudged a stick aside so as to let the flames breathe."
},
{
    "C096",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> with DET goal of <cause>",
    "The speaker of Parliament read a roll call of the 275 elected members with a goal of shaming the no-shows."
},
{
    "C097",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> with DET objective of <cause>",
    "The speaker of Parliament read a roll call of the 275 elected members with the objective of shaming the no-shows."
},
{
    "C098",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> on condition of <cause>",
    "Only on condition of a radical widening of definitions will it be possible to consider art the only social power."
},
{
    "C099",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause>, so <effect>",
    "We will probably have some votes, so we will maximize our time."
},
{
    "C100",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause>, and thus <effect>",
    "This detergent is highly concentrated and thus you will need to dilute it."
},
{
    "C101",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> to <cause>",
    "What should be done to provide a better statutory framework?"
},
{
    "C102",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> because <cause>",
    "Nearly every session since November has been adjourned because as few as 65 members made it to work."
},
{
    "C103",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect>, for <cause>",
    "That would be of tremendous help, for it is true that speculators bear blame."
},
{
    "C104",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "Given <cause>, <effect>",
    "Given that you can't make it, we'll have to postpone."
},
{
    "C105",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "In an attempt to <cause>, <effect>",
    "The fox leapt in an attempt to catch the mouse."
},
{
    "C106",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> lest <cause>",
    "He kept his headphones on lest he disturb anyone."
},
{
    "C107",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "Now that <cause>, <effect>",
    "Now that she is rich and famous, she is constantly being besieged by appeals for aid."
},
{
    "C108",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> so <cause>",
    "Masking tape is used to cover up some beams so that only one is triggered."
},
{
    "C109",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> thanks to <cause>",
    "Thanks to their fast action, we dodged a bullet."
},
{
    "C110",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> else <effect>",
    "We must govern effectively, else chaos will reign."
},
{
    "C111",
    CausalDegree::Inhibit,
    CausalOrder::EC,
    "<effect> unless <cause>",
    "We have not replaced the discipline of a lender not lending to a borrower unless the lender is sure that the borrower can repay."
},
{
    "C112",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> is DET cause of <effect>",
    "Confusion regarding the R.O.E. was the proximate cause of the death of at least four unarmed individuals."
},
{
    "C113",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "DET consequence of <cause> is <effect>",
    "A major consequence of deforestation is soil erosion."
},
{
    "C114",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "DET effect of <cause> is <effect>",
    "One effect of the Thirty Years' War was the severe depopulation of Europe."
},
{
    "C115",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> is grounds for <effect>",
    "This behavior is grounds for divorce!"
},
{
    "C116",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "the implications of <cause> are <effect>",
    "Lilly had not fully understood the implications of his first complaint."
},
{
    "C117",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> is the key to <effect>",
    "Happiness is the key to success."
},
{
    "C118",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> is DET necessary condition of <effect>",
    "The regulatory restraints that many experts regard as a necessary condition of technological progress are largely unnecessary."
},
{
    "C119",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "DET reason [that] <effect> is <cause>",
    "One of the reasons that JPMorgan Chase did better is they did not have embedded in that institution a trading house."
},
{
    "C120",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "DET reason for <effect> is <cause>",
    "My reason for leaving now is that I want to get home on time."
},
{
    "C121",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> is reason to <effect>",
    "I have reason to think you're a liar."
},
{
    "C122",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> (CausalConstruction{is} reason why <effect>",
    "This is the reason why I am opposed to the bill."
},
{
    "C123",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> is DET result of <cause>",
    "Success is the result of perfection, hard work, learning from failure, loyalty, and persistence.  The result: a neat kitchen hack!"
},
{
    "C124",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> (CausalConstruction{is} condition of <effect>",
    "A valid passport is condition of international travel."
},
{
    "C125",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> because of <cause>",
    "The Missouri lawsuit seeks to end what it calls a state voting ban for people under full guardianship because of mental illness."
},
{
    "C126",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> by <cause>",
    "We won the game by forfeit."
},
{
    "C128",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> for <cause>",
    "He thanked the crowd for listening.  You're a good man for helping out.  I'm running for prostate research."
},
{
    "C129",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> for the sake of <cause>",
    "It is discouraging to see citizens cooperating with the government for the sake of public safety denigrated as rats and tattletales."
},
{
    "C130",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> from <cause>",
    "He died from a blocked artery."
},
{
    "C131",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> from <cause>",
    "From the time of my third-grade class trip to the Brooklyn Botanic Garden, I understood flowers were my ticket to a world of beauty."
},
{
    "C132",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> in <cause>",
    "I left early in the hopes of beating the traffic."
},
{
    "C133",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "In light of <cause>, <effect>",
    "Formal charges were not warranted ''in light of his honest belief of the correctness of the mission R.O.E."
},
{
    "C134",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> into <effect>",
    "He tricked me into coming with."
},
{
    "C135",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> of <cause>",
    "He died of a blocked artery."
},
{
    "C136",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> out of <cause>",
    "He fled out of fear for his life."
},
{
    "C137",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> to <effect>",
    "We have the votes to pass it."
},
{
    "C138",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> with <cause>",
    "The paper was yellow with age."
},
{
    "C139",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> ensures <effect>",
    "We must ensure that taxpayers are not left holding the bag."
},
{
    "C140",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> guarantees <effect>",
    "Preparation will guarantee success!"
},
{
    "C141",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> makes certain <effect>",
    "We must make certain that nobody enters."
},
{
    "C142",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> assures <effect>",
    "He wants to assure a favorable vote."
},
{
    "C143",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "NP attributes <effect> to <cause>",
    "She attributed his bad temper to ill health."
},
{
    "C144",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "NP blames <cause> for <effect>",
    "We blamed the accident on her."
},
{
    "C145",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> brings <effect> to <effect>",
    "The confession of one of the accused brought the others to admit to the crime as well."
},
{
    "C146",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> causes <effect>",
    "Something that simple causes problems in subprime."
},
{
    "C147",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> comes from <cause>",
    "These threats come from unconstrained risk-taking."
},
{
    "C148",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> contributes to <effect>",
    "The colonel's ''miscommunication'' of the rules contributed to the deaths of four unarmed Iraqis."
},
{
    "C149",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> depends on <cause>",
    "His success here depends upon effort and ability."
},
{
    "C150",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> drives <effect>",
    "His behavior drove me to drink heavily."
},
{
    "C151",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> eases <effect>",
    "Tokyo's dominance of government eased efficient contact-making."
},
{
    "C152",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> enables <effect>",
    "This will in turn enable our economy to continue to grow."
},
{
    "C153",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> encourages <effect>",
    "His financial success encouraged him to look for a wife."
},
{
    "C154",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> facilitates <effect>",
    "The FDIC may set up a bridge bank to facilitate an orderly liquidation of an insolvent firm."
},
{
    "C155",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> feeds <effect>",
    "Racial profiling has fed a deep sense of persecution."
},
{
    "C156",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> fosters <effect>",
    "These texts foster an interest in learning new information."
},
{
    "C157",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> has <effect>",
    "My wife had me go to the doctor."
},
{
    "C158",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> helps <effect> <effect>",
    "Your steady leadership is helping us weather the storm."
},
{
    "C159",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> induces <effect> to <effect>",
    "We must not induce a migration of risk-taking activities to less-regulated or offshore institutions."
},
{
    "C160",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> inhibits <effect>",
    "Our regulatory structure severly inhibits our competitiveness."
},
{
    "C161",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> leads <effect> to <effect>",
    "Recent events have led the Basel Committee on Banking Supervision to consider higher capital charges for such items."
},
{
    "C162",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> leads to <effect>",
    "Sectarian divisions have often led to deadlock."
},
{
    "C163",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> makes for <effect>",
    "Their background made for a rocky relationship."
},
{
    "C164",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> means <effect>",
    "Having more chefs means that food gets out to customers faster."
},
{
    "C165",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> necessitates <effect>",
    "An appreciation of biological evolution does not necessitate a completely materialistic and deterministic worldview."
},
{
    "C166",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> is predicated on <cause>",
    "Peace is predicated on compromise, not firepower or belligerence."
},
{
    "C167",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> promotes <effect>",
    "This bill promotes consolidation and cooperation among regulatory agencies."
},
{
    "C168",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> prompts <effect>",
    "His death has prompted an industry-wide investigation of safety violations."
},
{
    "C169",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> provokes <effect>",
    "Their belligerence provoked a war."
},
{
    "C170",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> requires <cause>",
    "Combating the growing culture of fear will require a greater emphasis on the physical protection of witnesses."
},
{
    "C171",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "<effect> results from <cause>",
    "Her victory resulted from absentee ballots cast by the nursing home residents."
},
{
    "C172",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> results in <effect>",
    "This move resulted in disaster."
},
{
    "C173",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> spurs <effect>",
    "That should not obscure the real good that can be done in spurring a wider global fight against H.I.V."
},
{
    "C174",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> inspires <effect>",
    "Her story inspired me to call my own relatives."
},
{
    "C175",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> gives <effect>",
    "The presence of my father gave some peace of mind."
},
{
    "C176",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> averts <effect>",
    "Cuts could avert the worst consequences of climate change."
},
{
    "C177",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> avoids <effect>",
    "They wished to avoid a cascading effect."
},
{
    "C178",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> blocks <effect>",
    "His formal reprimand effectively blocks any chance for promotion."
},
{
    "C179",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> deters <effect>",
    "Only a health problem would deter him from seeking re-election."
},
{
    "C180",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> discourages <effect>",
    "This feeder discourages squirrels from stealing seeds."
},
{
    "C181",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> foils <effect>",
    "A brave policewoman foiled the armed robbery."
},
{
    "C182",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> hampers <effect>",
    "Their work is hampered by lack of funds."
},
{
    "C183",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> hinders <effect>",
    "The storm hindered our progress."
},
{
    "C184",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> impedes <effect>",
    "The sap causes swelling that can impede breathing."
},
{
    "C185",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> keeps <effect> from <effect>",
    "The cold kept me from going outside."
},
{
    "C186",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> restrains <effect> from <effect>",
    "The safety harness restrains workers from falling off the roof."
},
{
    "C187",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> wards off <effect>",
    "This cream will ward off premature sagging and wrinkles."
},
{
    "C188",
    CausalDegree::Inhibit,
    CausalOrder::EC,
    "<effect>, barring <cause>",
    "Barring clouds, it will be viewed by millions of people."
},
{
    "C189",
    CausalDegree::Facilitate,
    CausalOrder::CE,
    "<cause> gets <effect> to <effect>",
    "His wife got him to eat more vegetables."
},
{
    "C190",
    CausalDegree::Inhibit,
    CausalOrder::CE,
    "<cause> thwarts <effect>",
    "Private citizens have helped to thwart many of these attacks."
},
{
    "M001",
    CausalDegree::Facilitate,
    CausalOrder::EC,
    "the probable cause of <effect> was <cause",
    "The probable cause of the accident was distraction."
}
};
}

#endif