class SofaStats:
    Individual_Stats = [
        "totalPass",
        "accuratePass",
        "totalLongBalls",
        "accurateLongBalls",
        "goalAssist",
        "totalCross",
        "accurateCross",
        "aerialLost",
        "aerialWon",
        "duelLost",
        "duelWon",
        "challengeLost",
        "dispossessed",
        "totalContest",
        "wonContest",
        "shotOffTarget",
        "onTargetScoringAttempt",
        "goals",
        "totalClearance",
        "outfielderBlock",
        "interceptionWon",
        "totalTackle",
        "errorLeadToAShot",
        "ownGoals",
        "wasFouled",
        "fouls",
        "totalOffside",
        "goodHighClaim",
        "totalOffside",
        "minutesPlayed",
        "touches",
        "rating",
        "possessionLostCtrl",
        "expectedGoals",
        "keyPass",
        "expectedAssists",
        # GK stats
        "saves",
        "totalKeeperSweeper",
        "accurateKeeperSweeper",
        "goalsPrevented",
        "savedShotsFromInsideTheBox",
        "punches",
    ]

    Display_Individual_Stats = {
        "totalPass": "Total Passes",
        "accuratePass": "Accurate Passes",
        "totalLongBalls": "Total Long Balls",
        "accurateLongBalls": "Accurate Long Balls",
        "goalAssist": "Assists",
        "totalCross": "Total Crosses",
        "accurateCross": "Accurate Crosses",
        "aerialLost": "Aerial Duels Lost",
        "aerialWon": "Aerial Duels Won",
        "duelLost": "Duels Lost",
        "duelWon": "Duels Won",
        "challengeLost": "Challenges Lost",
        "dispossessed": "Times Dispossessed",
        "totalContest": "Total Contests",
        "wonContest": "Contests Won",
        "shotOffTarget": "Shots Off Target",
        "onTargetScoringAttempt": "Shots On Target",
        "goals": "Goals",
        "totalClearance": "Total Clearances",
        "outfielderBlock": "Blocked Shots",
        "interceptionWon": "Interceptions Won",
        "totalTackle": "Total Tackles",
        "errorLeadToAShot": "Errors Leading to Shots",
        "ownGoals": "Own Goals",
        "wasFouled": "Fouls Suffered",
        "fouls": "Fouls Committed",
        "totalOffside": "Total Offsides",
        "goodHighClaim": "Good High Claims",
        "minutesPlayed": "Minutes Played",
        "touches": "Touches",
        "rating": "Rating",
        "possessionLostCtrl": "Possession Lost (Control)",
        "expectedGoals": "Expected Goals",
        "keyPass": "Key Passes",
        "expectedAssists": "Expected Assists",
        # GK stats
        "saves": "Total Saves",
        "totalKeeperSweeper": "Total Keeper Sweepers",
        "accurateKeeperSweeper": "Accurate Keeper Sweepers",
        "goalsPrevented": "Goals Prevented",
        "savedShotsFromInsideTheBox": "Saves (Inside the Box)",
        "punches": "Punches"
    }
    
    Team_Stats_For_Tournament = [
        "goalsScored",
        "goalsConceded",
        "assists",
        "shots",
        "penaltyGoals",
        "penaltiesTaken",
        "successfulDribbles",
        "dribbleAttempts",
        "corners",
        "averageBallPossession",
        "totalPasses",
        "accuratePasses",
        "accuratePassesPercentage",
        "totalLongBalls",
        "accurateLongBalls",
        "accurateLongBallsPercentage",
        "totalCrosses",
        "accurateCrosses",
        "accurateCrossesPercentage",
        "cleanSheets",
        "interceptions",
        "saves",
        "errorsLeadingToShot",
        "totalDuels",
        "duelsWon",
        "duelsWonPercentage",
        "totalAerialDuels",
        "aerialDuelsWon",
        "aerialDuelsWonPercentage",
        "offsides",
        "fouls",
        "yellowCards",
        "yellowRedCards",
        "redCards",
        "shotsAgainst",
        "goalKicks",
        "ballRecovery",
        "freeKicks",
        "matches",
        "awardedMatches",
    ]

    Player_Stats_For_Tournament = [
        "rating",
        "goals",
        "assists",
        "expectedGoals",
        "expectedAssists",
        "goalsAssistsSum",
        "accuratePasses",
        "inaccuratePasses",
        "totalPasses",
        "accuratePassesPercentage",
        "accurateFinalThirdPasses",
        "keyPasses",
        "touches",
        "successfulDribbles",
        "successfulDribblesPercentage",
        "interceptions",
        "yellowCards",
        "directRedCards",
        "redCards",
        "accurateCrosses",
        "accurateCrossesPercentage",
        "totalShots",
        "shotsOnTarget",
        "shotsOffTarget",
        "shotsFromOutsideTheBox",
        "goalsFromOutsideTheBox",
        "shotsFromInsideTheBox",
        "goalsFromInsideTheBox",
        "aerialDuelsWon",
        "aerialDuelsWonPercentage",
        "totalDuelsWon",
        "totalDuelsWonPercentage",
        "minutesPlayed",
        "goalConversionPercentage",
        "penaltiesTaken",
        "penaltyGoals",
        "shotFromSetPiece",
        "accurateLongBalls",
        "accurateLongBallsPercentage",
        "clearances",
        "errorLeadToShot",
        "wasFouled",
        "fouls",
        "dribbledPast",
        "offsides",
        "blockedShots",
        "passToAssist",
        "saves",
        "cleanSheet",
        "crossesNotClaimed",
        "matchesStarted",
        "penaltyConversion",
        "totalCross",
        "duelLost",
        "aerialLost",
        "attemptPenaltyMiss",
        "totalLongBalls",
        "goalsConceded",
        "scoringFrequency",
        "yellowRedCards",
        "substitutionsIn",
        "substitutionsOut",
        "goalKicks",
        "ballRecovery",
        "appearances",
    ]

    Match_Stats = [
        "ballPossession",
        "expectedGoals",
        "bigChanceCreated",
        "totalShotsOnGoal",
        "goalkeeperSaves",
        "cornerKicks",
        "fouls",
        "passes",
        "totalTackle",
        "freeKicks",
        "yellowCards",
        "redCards",
        "shotsOnGoal",
        "hitWoodwork",
        "shotsOffGoal",
        "blockedScoringAttempt",
        "totalShotsInsideBox",
        "totalShotsOutsideBox",
        "bigChanceScored",
        "bigChanceMissed",
        "touchesInOppBox",
        "fouledFinalThird",
        "offsides",
        "accuratePasses",
        "throwIns",
        "finalThirdPhaseStatistic",
        "finalThirdEntries",
        "accurateLongBalls",
        "accurateCross",
        "duelWonPercent",
        "dispossessed",
        "groundDuelsPercentage",
        "aerialDuelsPercentage",
        "dribblesPercentage",
        "wonTacklePercent",
        "interceptionWon",
        "ballRecovery",
        "totalClearance",
        "errorsLeadToGoal",
        "goalsPrevented",
        "goalKicks",
        "accurateThroughBall"
    ]

    Display_Match_Stats = {
        "ballPossession": "Ball Possession %",
        "expectedGoals": "Expected Goals",
        "bigChanceCreated": "Big Chance Created",
        "totalShotsOnGoal": "Total Shots",
        "goalkeeperSaves": "Goalkeeper Saves",
        "cornerKicks": "Corner Kicks",
        "fouls": "Fouls",
        "passes": "Passes",
        "totalTackle": "Total Tackle",
        "freeKicks": "Free Kicks",
        "yellowCards": "Yellow Cards",
        "redCards": "Red Cards",
        "shotsOnGoal": "Shots on Goal",
        "hitWoodwork": "Hit Woodwork",
        "shotsOffGoal": "Shots off Goal",
        "blockedScoringAttempt": "Blocked Scoring Attempt",
        "totalShotsInsideBox": "Total Shots Inside Box",
        "totalShotsOutsideBox": "Total Shots Outside Box",
        "bigChanceScored": "Big Chance Scored",
        "bigChanceMissed": "Big Chance Missed",
        "touchesInOppBox": "Touches in Opponent's Box",
        "fouledFinalThird": "Fouled in Final Third",
        "offsides": "Offsides",
        "accuratePasses": "Accurate Passes",
        "throwIns": "Throw-Ins",
        "finalThirdPhaseStatistic": "Final Third Phase Statistic",
        "finalThirdEntries": "Final Third Entries",
        "accurateLongBalls": "Accurate Long Balls",
        "accurateCross": "Accurate Crosses",
        "duelWonPercent": "Duel Won Percentage",
        "dispossessed": "Dispossessed",
        "groundDuelsPercentage": "Ground Duels Percentage",
        "aerialDuelsPercentage": "Aerial Duels Percentage",
        "dribblesPercentage": "Dribbles Percentage",
        "wonTacklePercent": "Won Tackle Percentage",
        "interceptionWon": "Interceptions Won",
        "ballRecovery": "Ball Recovery",
        "totalClearance": "Total Clearances",
        "errorsLeadToGoal": "Errors Leading to Goal",
        "goalsPrevented": "Goals Prevented",
        "goalKicks": "Goal Kicks"
    }
        
